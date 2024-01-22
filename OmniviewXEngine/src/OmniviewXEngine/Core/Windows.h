#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#include "OmniviewXEngine/Events/Event.h"

namespace OmniviewXEngine
{
    struct WindowProps
    {
        std::string windowTitle;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string &title = "OmniviewXEngine",
                    uint32_t width = 1600, uint32_t height = 900)
            : windowTitle(title), Width(width), Height(height)
        {
        }
    };

    class Window
    {
    public:
        using EventCallBackFn = std::function<void(Event &)>;

        virtual ~Window() = default;
        virtual void OnUpdate() = 0;
        virtual void ClearColor() = 0;

            virtual uint32_t
            GetWindowWidth() const = 0;
        virtual uint32_t GetWindowHeight() const = 0;

        // window 相关的属性,垂直同步等
        virtual void SetEventCallBackFn(const EventCallBackFn &callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        virtual void *GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProps &props = WindowProps());
    };
};

#endif