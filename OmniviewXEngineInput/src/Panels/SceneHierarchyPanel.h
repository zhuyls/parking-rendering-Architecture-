#ifndef _SCENE_HIEARARCHY_PANEL_H_
#define _SCENE_HIEARARCHY_PANEL_H_

#include "OmniviewXEngine/Core/Base.h"
#include "OmniviewXEngine/Scene/Scene.h"
#include "OmniviewXEngine/Scene/Entity.h"

namespace OmniviewXEngine
{
    class SceneHierarchyPanel
    {
    public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();

        Entity GetSelectedEntity() const {return m_SelectionContext;}
        void SetSelectedEntity(Entity entity);

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
    };
}


#endif