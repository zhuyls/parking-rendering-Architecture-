#ifndef _EDITOR_LAYER_H_
#define _EDITOR_LAYER_H_

#include "OmniviewXEngine.h"
#include "Panels/SceneHierarchyPanel.h"
// #include "Panels/ContentBrowserPanel.h"

#include "OmniviewXEngine/Renderer/EditorCamera.h"
#include <string>

namespace OmniviewXEngine 
{
	// class EditorLayer : public Layer
	// {
	// public:
	// 	EditorLayer();
	// 	virtual ~EditorLayer() = default;

	// 	virtual void OnAttach() override;
	// 	virtual void OnDetach() override;

	// 	void OnUpdate(Timestep ts) override;
	// 	virtual void OnImGuiRender() override;
	// 	void OnEvent(Event& e) override;
	// private:
	// 	bool OnKeyPressed(KeyPressedEvent& e);
	// 	bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
	// private:
	// 	OmniviewXEngine::OrthographicCameraController m_CameraController;

	// 	// Temp
	// 	Ref<VertexArray> m_SquareVA;
	// 	Ref<Shader> m_FlatColorShader;
	// 	Ref<Framebuffer> m_Framebuffer;

	// 	Ref<Scene> m_ActiveScene;
	// 	Entity m_SquareEntity;
	// 	Entity m_CameraEntity;
	// 	Entity m_SecondCamera;

	// 	bool m_PrimaryCamera = true;

	// 	Ref<Texture2D> m_CheckerboardTexture;

	// 	bool m_ViewportFocused = false, m_ViewportHovered = false;
	// 	glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

	// 	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	// 	// Panels
	// 	SceneHierarchyPanel m_SceneHierarchyPanel;
	// };

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& event) override;

		// ImGui UI helpers
		bool Property(const std::string& name, bool& value);
	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
	
	private:
		OmniviewXEngine::OrthographicCameraController m_CameraController;

		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;

		Entity m_HoveredEntity;

		bool m_PrimaryCamera = true;

		EditorCamera m_EditorCamera;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;

		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
		int m_GizmoType = -1;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;

	};
}


#endif