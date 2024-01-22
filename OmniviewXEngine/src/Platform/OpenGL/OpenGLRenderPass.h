#ifndef _OPENGL_REDNERPASS_H_
#define _OPENGL_REDNERPASS_H_

#include "OmniviewXEngine/Renderer/RenderPass.h"
namespace OmniviewXEngine
{
    class OpenGLRenderPass : public RenderPass
    {
    public:
        OpenGLRenderPass(const RenderPassSpecification& spec);
        virtual ~OpenGLRenderPass();
        virtual const RenderPassSpecification& GetSpecification() const override { return m_Specification; }
	private:
		RenderPassSpecification m_Specification;
    };
}

#endif