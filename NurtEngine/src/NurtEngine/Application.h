#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace NurtEngine {

	class NURTENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// To be defined in the CLIENT
	Application* CreateApplication();
}
