
#include "Omniviewpch.h"
#include "OmniviewXEngine/Core/Application.h"
#include "OmniviewXEngine/Core/Log.h"
#include "OmniviewXEngine/Renderer/Renderer.h"
#include "OmniviewXEngine/Events/ApplicationEvent.h"
#include "OmniviewXEngine/Events/MouseEvent.h"
#include "OmniviewXEngine/Core/Assert.h"
#include "OmniviewXEngine/Utils/PlatformUtils.h"

namespace OmniviewXEngine 
{
	Application* Application::m_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec):
	m_Specification(spec)
	{
		OMNIVIEW_ASSERT(!m_Instance, "Application already exist!");

		m_Instance = this;

		//setting working directory here

		if (!m_Specification.WorkingDirectory.empty()) 
		{
			try 
			{
				std::experimental::filesystem::path workingDir = m_Specification.WorkingDirectory;
				std::experimental::filesystem::current_path(workingDir);
			} 
			catch (const std::experimental::filesystem::filesystem_error& e) 
			{
				std::cerr << "Error setting working directory: " << e.what() << std::endl;
    		}
		}

		m_Window = Window::Create(WindowProps(m_Specification.Name));
		m_Window->SetEventCallBackFn(OMNIVIEW_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		// pushback the imgui layer
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while(m_Running)
		{
			float time = Time::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
				{
					layer->OnUpdate(timestep);
				}

				m_ImGuiLayer->Begin();

				{
					for (Layer* layer : m_LayerStack)
					{
						layer->OnImGuiRender();
					}
						
				}

				m_ImGuiLayer->End();
					
			}

			m_Window->OnUpdate();
		}

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		
		dispatcher.Dispatch<WindowCloseEvent>(OMNIVIEW_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(OMNIVIEW_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.m_Handled)
			{
				break;
			}
				
			(*it)->OnEvent(e);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		std::cout << "Application::OnWindowClose() = " << std::endl;
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		return false;
	}

}