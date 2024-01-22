#include "OmniviewXEngine.h"
#include "EditorLayer.h"


namespace OmniviewXEngine
{
    class OmniviewInputApp : public Application
    {
    public:
        OmniviewInputApp(const ApplicationSpecification& spec):
            Application(spec)
        {
            PushLayer(new EditorLayer());
        }
    };

    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        ApplicationSpecification spec;
        spec.Name = "OmniviewInputApp";
        spec.CommandLineArgs = args;

        return new OmniviewInputApp(spec);
    }
}