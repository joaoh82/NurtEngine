#include "nepch.h"
#include "Application.h"

#include "NurtEngine/Events/ApplicationEvent.h"
#include "NurtEngine/Log.h"

namespace NurtEngine {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			NE_TRACE(e);
		}

		while (true);
	}

}


