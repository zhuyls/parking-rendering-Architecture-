#include "OmniviewXEngine/Core/Timestep.h"

namespace OmniviewXEngine
{
    Timestep::Timestep(float time):
    m_Time(time)
    {

    }

	Timestep::operator float() const 
    { 
        return m_Time; 
    }

	float Timestep::GetSeconds() const 
    { 
        return m_Time; 
    }

	float Timestep::GetMilliseconds() const 
    { 
        return m_Time * 1000.0f; 
    }
}