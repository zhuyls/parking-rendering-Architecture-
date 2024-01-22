#ifndef _IMGUILAYER_H_
#define _IMGUILAYER_H_

#include "OmniviewXEngine/Core/Layer.h"
#include "OmniviewXEngine/Events/ApplicationEvent.h"
#include "OmniviewXEngine/Events/KeyEvent.h"
#include "OmniviewXEngine/Events/MouseEvent.h"

namespace OmniviewXEngine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

        void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
	private:
		bool m_BlockEvents = true;

    };
}

#endif