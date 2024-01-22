#ifndef _APP2D_H_
#define _APP2D_H_

#include "OmniviewXEngine.h"

class App2D : public OmniviewXEngine::Layer
{
public:
    App2D();
    virtual ~App2D() = default;
    
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    void OnUpdate(OmniviewXEngine::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(OmniviewXEngine::Event& event) override;

private:
    uint32_t m_FPS = 0;
    OmniviewXEngine::OrthographicCameraController   m_CameraController;
    OmniviewXEngine::Ref<OmniviewXEngine::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};

#endif