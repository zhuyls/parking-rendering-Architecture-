#include "Omniviewpch.h"
#include "OmniviewXEngine/Renderer/VertexArray.h"

#include "OmniviewXEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace OmniviewXEngine 
{

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:     OMNIVIEW_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		OMNIVIEW_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}