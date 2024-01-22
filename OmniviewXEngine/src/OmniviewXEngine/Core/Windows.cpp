#include "Omniviewpch.h"
#include "OmniviewXEngine/Core/Windows.h"

#ifdef OMNIVIEW_PLATFORM_LINUX
    #include "Platform/Linux/LinuxWindow.h"
#endif

namespace OmniviewXEngine
{
    Scope<Window> Window::Create(const WindowProps& props)
	{
		printf("Scope<Window> Window::\n");
	#ifdef OMNIVIEW_PLATFORM_LINUX
		return CreateScope<LinuxWindow>(props);
	#endif
	}
}