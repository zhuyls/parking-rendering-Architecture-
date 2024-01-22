#ifndef _PLATFORMUTILS_H_
#define _PLATFORMUTILS_H_

#include <string>
#include <optional>

namespace OmniviewXEngine
{
    class FileDialogs
	{
	public:
		// These return empty strings if cancelled
		static std::optional<std::string> OpenFile(const std::string& filter);
		static std::optional<std::string> SaveFile(const std::string& filter);
	};

	class Time
	{
	public:
		static float GetTime();
	};
}

#endif