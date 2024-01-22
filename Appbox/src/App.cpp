#include "OmniviewXEngine.h"
// #include <OmniviewXEngine/Core/EntryPoint.h>

#include "ExampleLayer.h"
#include "App2D.h"


class Sandbox : public OmniviewXEngine::Application
{
public:
	Sandbox(const OmniviewXEngine::ApplicationSpecification& spec):
	OmniviewXEngine::Application(spec)
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

OmniviewXEngine::Application* OmniviewXEngine::CreateApplication(ApplicationCommandLineArgs args)
{

	ApplicationSpecification spec;
	spec.Name = "OmniviewXEngineInput";
	spec.WorkingDirectory = "/home/adas/adas/CG/OmniviewXEngine/OmniviewXEngineInput/";
	spec.CommandLineArgs = args;
	
	return new Sandbox(spec);
}