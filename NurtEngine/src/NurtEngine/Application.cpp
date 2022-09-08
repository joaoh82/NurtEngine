#include "nepch.h"
#include "Application.h"

#include "NurtEngine/Log.h"

#include <glad/glad.h>

namespace NurtEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		NE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	// Pushing Layer into the LayerStack
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	// Pushing OverLay into the LayerStack
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			// Iterates over all Layers and OverLays
			for (Layer* layer : m_LayerStack) // We can use this because we implemented Begin() and End()
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		// If event is a WindowCloseEvent, then calls OnWindowClose event
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		// Logging events for debugging purposes
		//NE_CORE_TRACE("{0}", e);

		// Iterating backwards through the LayerStack and calling ObEvent on every layer
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled) // If Event was Handled by Layer or OverLay (which come first) we break out of the for loop.
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		// This will terminate the application on the next loop
		m_Running = false;

		return true;
	}

}


