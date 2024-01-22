#ifndef _RENDERPASS_H_
#define _RENDERPASS_H_

#include "OmniviewXEngine/Core/Base.h"
#include "Framebuffer.h"

namespace OmniviewXEngine
{
    struct RenderPassSpecification
    {
        Ref<Framebuffer> TargetFramebuffer;
    };

    class RenderPass
    {
    public:
        virtual ~RenderPass() {}
        
        virtual const RenderPassSpecification& GetSpecification() const = 0;

		static Ref<RenderPass> Create(const RenderPassSpecification& spec);
    };

}



#endif