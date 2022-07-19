#pragma once

#include "Core.h"

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
