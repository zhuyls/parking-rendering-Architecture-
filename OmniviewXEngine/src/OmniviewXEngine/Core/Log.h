#ifndef _LOG_H_
#define _LOG_H_

#include "OmniviewXEngine/Core/Base.h"
#define GLM_ENABLE_EXPERIMENTAL

#include "glm/gtx/string_cast.hpp"
#include "glm/detail/qualifier.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace OmniviewXEngine
{
    class Log
    {
    public:
        static void Init();
        static Ref<spdlog::logger>& GetCoreLogger()   {return m_CoreLogger;}
        static Ref<spdlog::logger>& GetClientLogger() {return m_ClientLogger;}
    private:
		static Ref<spdlog::logger> m_CoreLogger;
		static Ref<spdlog::logger> m_ClientLogger;
    };
}

// glm::qualifier Q
// 在GLM库中，glm::qualifier是用于标识限定符的命名空间。
// glm::qualifier命名空间提供了一些限定符，用于在GLSL风格的数学函数中指定运算符行为
template<typename Ostream, glm::length_t L, typename T, glm::qualifier Q>
inline Ostream& operator<<(Ostream& os, const glm::vec<L, T, Q>& vector)
{
    return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

// __VA_ARGS__是C/C++语言中的宏扩展特性之一，它用于表示宏定义中的可变参数部分。
// __VA_ARGS__允许在宏定义中使用可变数量的参数，并将这些参数作为一个整体进行处理。
// 它通常用于宏定义中需要接受不定数量参数的情况

// Core log macros
#define OMNIVIEW_CORE_TRACE(...)    ::OmniviewXEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OMNIVIEW_CORE_INFO(...)     ::OmniviewXEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OMNIVIEW_CORE_WARN(...)     ::OmniviewXEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OMNIVIEW_CORE_ERROR(...)    ::OmniviewXEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OMNIVIEW_CORE_CRITICAL(...) ::OmniviewXEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define OMNIVIEW_TRACE(...)         ::OmniviewXEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OMNIVIEW_INFO(...)          ::OmniviewXEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define OMNIVIEW_WARN(...)          ::OmniviewXEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OMNIVIEW_ERROR(...)         ::OmniviewXEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define OMNIVIEW_CRITICAL(...)      ::OmniviewXEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif