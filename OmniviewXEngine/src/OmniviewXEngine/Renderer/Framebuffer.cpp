#include "Omniviewpch.h"
#include "OmniviewXEngine/Renderer/Framebuffer.h"

#include "OmniviewXEngine/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace OmniviewXEngine 
{
	
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    OMNIVIEW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		OMNIVIEW_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

