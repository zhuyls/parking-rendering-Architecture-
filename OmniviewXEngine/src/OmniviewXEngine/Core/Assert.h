#ifndef _ASSERT_H_
#define _ASSERT_H_

#include "OmniviewXEngine/Core/Base.h"
#include "OmniviewXEngine/Core/Log.h"
#include <experimental/filesystem>

// __VA_ARGS__是C/C++中的特殊宏参数，用于表示可变数量的参数。
// 在宏定义中，__VA_ARGS__表示了一个占位符，用于接收宏在调用时传递的可变数量的参数。
// 它允许在宏展开时，将参数列表作为一个整体进行处理。

#ifdef OMNIVIEW_ENABLE_ASSERTS

#define OMNIVIEW_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { OMNIVIEW##type##ERROR(msg, __VA_ARGS__); OMNIVIEW_DEBUGBREAK(); } }
#define OMNIVIEW_INTERNAL_ASSERT_WITH_MSG(type, check, ...) OMNIVIEW_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define OMNIVIEW_INTERNAL_ASSERT_NO_MSG(type, check) OMNIVIEW_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", OMNIVIEW_STRINGIFY_MACRO(check), std::experimental::filesystem::path(__FILE__).filename().string(), __LINE__)

#define OMNIVIEW_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define OMNIVIEW_INTERNAL_ASSERT_GET_MACRO(...) OMNIVIEW_EXPAND_MACRO( OMNIVIEW_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, OMNIVIEW_INTERNAL_ASSERT_WITH_MSG, OMNIVIEW_INTERNAL_ASSERT_NO_MSG) )


// Currently accepts at least the condition and one additional parameter (the message) being optional
#define OMNIVIEW_ASSERT(...) OMNIVIEW_EXPAND_MACRO( OMNIVIEW_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define OMNIVIEW_CORE_ASSERT(...) OMNIVIEW_EXPAND_MACRO( OMNIVIEW_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )

#else
    #define OMNIVIEW_ASSERT(...)
    #define OMNIVIEW_CORE_ASSERT(...)
#endif

#endif