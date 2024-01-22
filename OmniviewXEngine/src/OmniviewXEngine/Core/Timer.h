#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

namespace OmniviewXEngine
{
    class Timer
    {
    public:
		Timer();
		void Reset();
		float Elapsed();
		float ElapsedMillis();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};
}

#endif