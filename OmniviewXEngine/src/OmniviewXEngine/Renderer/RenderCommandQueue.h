#ifndef _RENDERCOMMAND_QUEUE_H_
#define _RENDERCOMMAND_QUEUE_H_

#include "Omniviewpch.h"

namespace OmniviewXEngine
{
    class RenderCommandQueue
    {
    public:
        typedef void(*RenderCommandFn)(void*);

        RenderCommandQueue();
		~RenderCommandQueue();

        void* Allocate(RenderCommandFn func, uint32_t size);

		void Execute();
    
    private:
        uint8_t* m_CommandBuffer;
		uint8_t* m_CommandBufferPtr;
		uint32_t m_CommandCount = 0;

    };
}

#endif