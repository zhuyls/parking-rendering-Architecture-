#include "OmniviewXEngine/Renderer/GraphicsContext.h"
#include "Omniviewpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace OmniviewXEngine 
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
	}

}