#pragma once

#include "nepch.h"
#include "NurtEngine/Core.h"

namespace NurtEngine {

	// Events in NurtEngine are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right away.
	// For the future, a better strategy might be to buffer events in an event bus
	// and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// EventCategory is an easy way to filter events that we only to deal with at the moment
	// BIT() defined in core.h
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// Event is base class for all events
	class NURTENGINE_API Event
	{
		friend class EventDispatcher;

	public:

		// Pure functions

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		// ToString is a debugging function and can be overridden in any way we like
		virtual std::string ToString() const { return GetName(); }

		// IsInCategory is an easy way to filter out the events
		// If returns 0 is not in the category
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		// This is an easy flag for us to know if the event was already handled
		bool m_Handled = false;
	};

	// EventDispatcher is a way for us to dispatch event based on their type
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		
		// We create an instance of dispatcher with the event to be propagated
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// After constructed we can call this Dispatch function a number of times with the event
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// The event is only propagated is the event being sent 
			// is of the same type of the event in the constructor
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
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