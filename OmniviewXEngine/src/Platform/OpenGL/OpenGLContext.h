#ifndef _OPENGLCONTEXT_H_
#define _OPENGLCONTEXT_H_

#include "OmniviewXEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace OmniviewXEngine 
{

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}

#endif