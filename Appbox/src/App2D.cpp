#include "App2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

App2D::App2D()
:Layer("Appbox"),m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
,m_CameraController(1280.0f / 720.0f)
{
    
}

void App2D::OnAttach()
{
    m_CheckerboardTexture = OmniviewXEngine::Texture2D::Create("/home/adas/adas/CG/OmniviewXEngine/Appbox/assets/textures/Checkerboard.png");
}

void App2D::OnDetach()
{
   
}

void App2D::OnUpdate(OmniviewXEngine::Timestep ts)
{
    m_FPS = (uint32_t)1000.0/ts.GetMilliseconds();

    m_CameraController.OnUpdate(ts);

    OmniviewXEngine::Renderer2D::ResetStats();

    OmniviewXEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	OmniviewXEngine::RenderCommand::Clear();

    static float rotation = 0.0f;
	rotation += ts * 50.0f;

    OmniviewXEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
    OmniviewXEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
    OmniviewXEngine::Renderer2D::EndScene();
   
}

void App2D::OnImGuiRender()
{
    ImGui::Begin("Settings");

    auto status = OmniviewXEngine::Renderer2D::GetStats();
    
    ImGui::Text("FPS: %d", m_FPS);
    ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", status.DrawCalls);
	ImGui::Text("Quads: %d", status.QuadCount);
	ImGui::Text("Vertices: %d", status.GetTotalVertexCount());
	ImGui::Text("Indices: %d", status.GetTotalIndexCount());

    ImGui::End();
}

void App2D::OnEvent(OmniviewXEngine::Event& event)
{
    m_CameraController.OnEvent(event);
}