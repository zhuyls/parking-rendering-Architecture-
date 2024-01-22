#ifndef _APPLICATION_H_
#define _APPLICATION_H_


#include "OmniviewXEngine/Core/Base.h"
#include "OmniviewXEngine/Core/Windows.h"
#include "OmniviewXEngine/Events/Event.h"
#include "OmniviewXEngine/Events/ApplicationEvent.h"
#include "OmniviewXEngine/Core/LayerStack.h"
#include "OmniviewXEngine/Core/Timestep.h"
#include "OmniviewXEngine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace OmniviewXEngine 
{

	struct ApplicationCommandLineArgs
	{
		int CommandCount = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			OMNIVIEW_CORE_ASSERT(index < CommandCount);
			return Args[index];
		}

	};

	struct ApplicationSpecification
	{
		std::string Name = "OmniviewXApplication";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& spec);
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() {return *m_Window;}

		void Close();

		ImGuiLayer* GetImGuiLayer() {return m_ImGuiLayer;}
		
		static Application& GetApplication() { return *m_Instance; }
		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ApplicationSpecification 	m_Specification;
		ApplicationCommandLineArgs  m_CommandLineArgs;
		Scope<Window> 				m_Window;
		ImGuiLayer* 				m_ImGuiLayer;
		bool						m_Running = true;
		bool    					m_Minimized = false;
		LayerStack 					m_LayerStack;
		float 						m_LastFrameTime = 0.0f;
	private:
		static Application*  m_Instance; // singleon
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);

}

#endif