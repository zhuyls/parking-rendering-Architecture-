#include "Omniviewpch.h"

#include <glad/glad.h>

#include "Platform/Linux/LinuxWindow.h"

#include "OmniviewXEngine/Events/ApplicationEvent.h"
#include "OmniviewXEngine/Events/KeyEvent.h"
#include "OmniviewXEngine/Events/MouseEvent.h"

#include "Platform/OpenGL/OpenGLContext.h"



namespace OmniviewXEngine
{

    static uint8_t s_GLFWWindowCount = 0;  // static variable s_ 命名

    static void GLFWErrorCallback(int error, const char* description)
	{
		OMNIVIEW_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

    LinuxWindow::LinuxWindow(const WindowProps& props)
    {
        Init(props);
    }
    
    LinuxWindow::~LinuxWindow()
    {

    }

	void LinuxWindow::ClearColor()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3,0.3,0.3,1.0);
	}

    void LinuxWindow::Init(const WindowProps& props)
    {
        m_Data.windowTitle = props.windowTitle;
		m_Data.windowWidth = props.Width;
		m_Data.windowHeight = props.Height;

        // OMNIVIEW_CORE_INFO("Creating window {0} ({1}, {2})", props.windowTitle, props.Width, props.Height);

        if (s_GLFWWindowCount == 0)
		{
			int success = glfwInit();
			// OMNIVIEW_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

        {
        #if defined(OMNIVIEW_DEBUG)
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
        #endif
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.windowTitle.c_str(), nullptr, nullptr);
		++s_GLFWWindowCount;

        m_Context = GraphicsContext::Create(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

        // set the glfw callback
        // lambda 可以向函数指针转换

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.windowWidth = width;
			data.windowHeight = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			std::cout << "glfwSetWindowCloseCallback() = " << std::endl;
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event); //最终调用在这里
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});

    }

	void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
		{
			glfwTerminate();
		}
    }

    void LinuxWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

    void LinuxWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.Vsync = enabled;
	}

	bool LinuxWindow::IsVSync() const
	{
		return m_Data.Vsync;
	}

}