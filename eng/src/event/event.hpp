#pragma once
#include <string>

namespace eng
{
    enum class EventType
    {
	WINDOW_CLOSED,
	WINDOW_RESIZED,
	MOUSE_MOVED,
	KEY_PRESSED,
	KEY_RELEASED,
	KEY_HELD
    };

#define EVENT_TYPE(type) static EventType s_GetType() { return EventType::type; } \
    virtual const EventType getType() const { return s_GetType(); } \
    virtual const char* getName() const { return #type; }

    class Event
    {
	public:
	    bool isHandled = false;
	public:
	    Event() = default;
	    virtual const char* getName() const = 0;
	    virtual const EventType getType() const = 0;
	    virtual std::string toString() const { return getName(); }
    };

    class WindowClosed : public Event
    {
	public:
	    EVENT_TYPE(WINDOW_CLOSED);
    };

    class EventDispatcher
    {
	private:
	    Event& m_Event;
	public:
	    EventDispatcher(Event& e)
		: m_Event(e) {};

	    template<typename T, typename F>
	    bool dispatch(F fn)
	    {
		if(T::s_GetType() == m_Event.getType())
		{
		    m_Event.isHandled = fn(static_cast<T&>(m_Event));
		    return true;
		}

		return false;
	    }


    };
}
