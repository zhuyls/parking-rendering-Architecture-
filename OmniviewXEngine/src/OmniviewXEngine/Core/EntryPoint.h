#ifndef _ENTRYPOINT_H_
#define _ENTRYPOINT_H_

#include "OmniviewXEngine/Core/Application.h"
#include "OmniviewXEngine/Core/Base.h"

#ifdef OMNIVIEW_PLATFORM_LINUX

extern OmniviewXEngine::Application* OmniviewXEngine::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	// initialize the spdlog
	OmniviewXEngine::Log::Init();
	auto app = OmniviewXEngine::CreateApplication({argc, argv});
	app->Run();
	delete app;
	return 0;
}

#endif

#endif