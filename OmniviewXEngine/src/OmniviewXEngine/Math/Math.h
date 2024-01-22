#ifndef _MATH_H_
#define _MATH_H_

#include <glm/glm.hpp>

namespace OmniviewXEngine::Math
{
    bool DecomposeTransform(const glm::mat4& transform, glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale);
}

#endif