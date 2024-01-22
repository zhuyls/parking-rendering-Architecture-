#ifndef _LAYER_H_
#define _LAYER_H_

#include "OmniviewXEngine/Core/Base.h"
#include "OmniviewXEngine/Events/Event.h"
#include "OmniviewXEngine/Core/Timestep.h"

namespace OmniviewXEngine
{
    class Layer
    {
    public:
      Layer(const std::string& name = "Layer");
      virtual ~Layer() = default;
      virtual void OnAttach() {}
      virtual void OnDetach() {}
      virtual void OnUpdate(Timestep ts) {}
      virtual void OnImGuiRender() {}
      virtual void OnEvent(Event& event) {}
      const std::string& GetName() const { return m_DebugName; }
    protected:
		  std::string m_DebugName;
    };
}


#endif