#include "Omniviewpch.h"
#include "RenderPass.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLRenderPass.h"

namespace OmniviewXEngine
{
    Ref<RenderPass> RenderPass::Create(const RenderPassSpecification& spec)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:    OMNIVIEW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLRenderPass>(spec);
		}

		OMNIVIEW_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}