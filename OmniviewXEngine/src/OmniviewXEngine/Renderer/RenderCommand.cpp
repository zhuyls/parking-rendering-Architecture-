#include "Omniviewpch.h"
#include "OmniviewXEngine/Renderer/RenderCommand.h"

namespace OmniviewXEngine 
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}