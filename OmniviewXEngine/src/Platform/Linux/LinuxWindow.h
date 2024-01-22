#ifndef _LINUXWINDOW_H_
#define _LINUXWINDOW_H_

#include "OmniviewXEngine/Core/Windows.h"
#include "OmniviewXEngine/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace OmniviewXEngine
{
    class LinuxWindow : public Window
    {
    public: 
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();

        void OnUpdate() override;

        void ClearColor() override;

        unsigned int GetWindowWidth()  const override { return m_Data.windowWidth; }
		unsigned int GetWindowHeight() const override { return m_Data.windowHeight; }

		// Window attributes
		void SetEventCallBackFn(const EventCallBackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
    
    private:
        GLFWwindow*             m_Window;
        Scope<GraphicsContext>  m_Context;

        struct WindowData
        {
            std::string windowTitle;
            unsigned int windowWidth;
            unsigned int windowHeight;
            bool Vsync;  //垂直同步

            EventCallBackFn EventCallback;
        };

        WindowData         m_Data;

    };
}

#endif