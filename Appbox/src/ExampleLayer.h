#ifndef _EXAMPLELAYER_H_
#define _EXAMPLELAYER_H_

#include "OmniviewXEngine.h"

class ExampleLayer : public OmniviewXEngine::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;
    
    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(OmniviewXEngine::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(OmniviewXEngine::Event& event) override;

private:
    OmniviewXEngine::ShaderLibrary  m_ShaderLibrary;

    OmniviewXEngine::Ref<OmniviewXEngine::Shader> m_Shader;
    OmniviewXEngine::Ref<OmniviewXEngine::VertexArray> m_VertexArray;

	OmniviewXEngine::Ref<OmniviewXEngine::Shader> m_FlatColorShader;
	OmniviewXEngine::Ref<OmniviewXEngine::VertexArray> m_SquareVA;

	OmniviewXEngine::Ref<OmniviewXEngine::Texture2D> m_Texture, m_OpenGLLogoTexture;

	OmniviewXEngine::OrthographicCameraController m_CameraController;

    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

};

#endif