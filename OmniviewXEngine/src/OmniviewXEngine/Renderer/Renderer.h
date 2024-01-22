#ifndef _RENDREER_H_
#define _RENDREER_H_

#include "OmniviewXEngine/Renderer/RenderCommand.h"

#include "OmniviewXEngine/Renderer/OrthographicCamera.h"
#include "OmniviewXEngine/Renderer/Shader.h"

namespace OmniviewXEngine 
{

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();
		
		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> s_SceneData;
	};
}

#endif