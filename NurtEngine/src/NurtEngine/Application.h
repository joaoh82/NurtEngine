#pragma once

#include "Core.h"

#include "Window.h"
#include "NurtEngine/LayerStack.h"
#include "NurtEngine/Events/Event.h"
#include "NurtEngine/Events/ApplicationEvent.h"

namespace NurtEngine {

	class NURTENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};
	
	// To be defined in the CLIENT
	Application* CreateApplication();
}
