#ifndef _TIMESTEP_H_
#define _TIMESTEP_H_

namespace OmniviewXEngine 
{
	class Timestep
	{
	public:
		Timestep(float time = 0.0f);
		operator float() const;
		float GetSeconds() const;
		float GetMilliseconds() const;
	private:
		float m_Time;
	};

}

#endif