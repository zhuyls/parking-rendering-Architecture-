#ifndef _OMNIVIEWPCH_H_
#define _OMNIVIEWPCH_H_

#include "OmniviewXEngine/Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "OmniviewXEngine/Core/Base.h"
#include "OmniviewXEngine/Core/Log.h"

#ifdef OMNIVIEW_PLATFORM_LINUX
	#include "OmniviewXEngine/Core/Windows.h"
#endif

// #include "Hazel/Debug/Instrumentor.h"

#endif