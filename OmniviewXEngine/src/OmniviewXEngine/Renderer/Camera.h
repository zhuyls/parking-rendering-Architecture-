#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>

namespace OmniviewXEngine 
{

	class Camera
	{
	public:
		Camera() = default;
		Camera(const glm::mat4& projection)
		: m_Projection(projection) 
        {

        }

		virtual ~Camera() = default;

		const glm::mat4& GetProjection() const 
        { 
            return m_Projection; 
        }
        
	protected:
		glm::mat4 m_Projection = glm::mat4(1.0f);
	};

}

#endif