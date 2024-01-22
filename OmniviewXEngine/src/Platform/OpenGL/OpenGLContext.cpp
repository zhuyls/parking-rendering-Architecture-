
#include "Omniviewpch.h"
#include "Platform/OpenGL/OpenGLContext.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace OmniviewXEngine
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
    :m_WindowHandle(windowHandle)
    {
        // OMNIVIEW_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

	void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

	void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}

