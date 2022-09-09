#pragma once

#include "NurtEngine/Layer.h"
#include "NurtEngine/Events/ApplicationEvent.h"
#include "NurtEngine/Events/KeyEvent.h"
#include "NurtEngine/Events/MouseEvent.h"

namespace NurtEngine {

	class NURTENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		// When a layer is pushed on to the LayerStack
		void OnAttach();
		void OnDetach();
		// When an event gets sent to the layer
		void OnEvent(Event& event);
		void OnUpdate();
	
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;

	};

}