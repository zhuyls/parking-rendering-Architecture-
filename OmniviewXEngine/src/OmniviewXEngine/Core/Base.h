#ifndef _BASE_H_
#define _BASE_H_

#include "PlatformDetection.h"
#include <memory>

#if defined(OMNIVIEW_DEBUG)
   #ifdef OMNIVIEW_PLATFORM_LINUX
        #include <signal.h>
        // raise(SIGTRAP)是一个函数调用，用于在程序中触发调试中断或生成断点。
        // 它通过向当前进程发送SIGTRAP信号来实现这一目的。
        // SIGTRAP是一个信号常量，表示调试中断信号。当进程接收到SIGTRAP信号时，
        // 它会中断当前执行的代码，并通知相关的调试器。
		#define OMNIVIEW_DEBUGBREAK() raise(SIGTRAP)
    #else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define OMNIVIEW_ENABLE_ASSERTS
#else
	#define OMNIVIEW_DEBUGBREAK()
#endif

#define OMNIVIEW_EXPAND_MACRO(x) x
#define OMNIVIEW_STRINGIFY_MACRO(x) #x     // #是一个预处理运算符，称为字符串化运算符

#define BIT(x) (1 << x)

#define OMNIVIEW_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace OmniviewXEngine 
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	using byte = uint8_t;

}

#endif

#include "OmniviewXEngine/Core/Log.h"
#include "OmniviewXEngine/Core/Assert.h"