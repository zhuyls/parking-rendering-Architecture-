#ifndef _EVENT_H_
#define _EVENT_H_

#include "OmniviewXEngine/Core/Base.h"
#include <functional>
#include <sstream>
#include <fstream>

namespace OmniviewXEngine
{
    enum class EventType 
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
	};

    /*
		对于LeftMouseButtonDown这个事件，我们希望它同时属于MouseButton，Mouse和Input事件，
		当拥有了这种标记之后，我们只需要用位或操作，就可以获得它新的Category：
		// EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput
		// =>10000 | 1000 | 10
		// =>10000 | 01000 | 00010
		// =>11010

		//当调用IsInCategory(EventCategoryMouseButton)时，这段逻辑就变成了
		//return 10000 & 11010;
		//=> return 10000;
	*/

    #define EVENT_CLASS_TYPE(type) static  EventType GetStaticType() { return EventType::type;} \
                                   virtual EventType GetEventType() const override { return GetStaticType(); }\
                                   virtual const char* GetName() const override {return #type;}

    #define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return category;}

    class Event
    {
    public:
        virtual ~Event() = default;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetEventCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName();}

        bool IsInCategory(EventCategory category)
        {
            return GetEventCategoryFlags() & category;
        }

    public:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event) 
        :m_Event(event)
        {

        }

        template <typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
		Event& m_Event;

    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}


#endif