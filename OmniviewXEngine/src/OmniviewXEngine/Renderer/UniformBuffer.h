#ifndef _UNIFORMBUFFER_H_
#define _UNIFORMBUFFER_H_

#include "OmniviewXEngine/Core/Base.h"

namespace OmniviewXEngine 
{

	class UniformBuffer
	{
	public:
		virtual ~UniformBuffer() {}
		virtual void SetData(const void* data, uint32_t size, uint32_t offset = 0) = 0;
		
		static Ref<UniformBuffer> Create(uint32_t size, uint32_t binding);
	};

}



#endif