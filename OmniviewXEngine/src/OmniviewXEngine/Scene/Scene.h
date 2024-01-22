#ifndef _SCENE_H_
#define _SCENE_H_

#include "OmniviewXEngine/Core/Timestep.h"
#include "OmniviewXEngine/Core/UUID.h"
#include "OmniviewXEngine/Renderer/EditorCamera.h"
#include "OmniviewXEngine/Renderer/OrthographicCamera.h"

#include "../entt/include/entt.hpp"


namespace OmniviewXEngine
{
  	// class Entity;

	// class Scene
	// {
	// public:
	// 	Scene();
	// 	~Scene();

	// 	Entity CreateEntity(const std::string& name = std::string());
	// 	void DestroyEntity(Entity entity);

	// 	void OnUpdateRuntime(Timestep ts);
	// 	void OnUpdateEditor(Timestep ts, EditorCamera& camera);
	// 	void OnViewportResize(uint32_t width, uint32_t height);

	// 	Entity GetPrimaryCameraEntity();
	// private:
	// 	template<typename T>
	// 	void OnComponentAdded(Entity entity, T& component);
	// private:
	// 	entt::registry m_Registry;
	// 	uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

	// 	friend class Entity;
	// 	friend class SceneSerializer;
	// 	friend class SceneHierarchyPanel;
	// };

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void DestroyEntity(Entity entity);

		void OnUpdate(Timestep ts);
		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);
		void OnUpdateScene(Timestep ts, OrthographicCamera& camera);
		void OnViewportResize(uint32_t width, uint32_t height);
		
		Entity GetPrimaryCameraEntity();
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
	public:
		entt::registry m_Registry;
	private:
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};


}

#endif