#ifndef _INPUT_H_
#define _INPUT_H_


#include "OmniviewXEngine/Core/KeyCodes.h"
#include "OmniviewXEngine/Core/MouseCodes.h"

#include <glm/glm.hpp>


namespace OmniviewXEngine
{
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseCodes button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

    };
}

#endif