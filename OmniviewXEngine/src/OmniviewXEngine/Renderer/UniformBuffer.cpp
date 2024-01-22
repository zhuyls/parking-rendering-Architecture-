#include "Omniviewpch.h"
#include "UniformBuffer.h"

#include "OmniviewXEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"

namespace OmniviewXEngine 
{

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    OMNIVIEW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		OMNIVIEW_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
