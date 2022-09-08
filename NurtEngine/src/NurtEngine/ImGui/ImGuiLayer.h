#pragma once

#include "NurtEngine/Layer.h"

namespace NurtEngine {

	class NURTENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		// When a layer is pushed on to the LayerStack
		void OnAttach();
		void OnDetach();

		void OnUpdate();

		// When an event gets sent to the layer
		void OnEvent(Event& event);

	private:
		float m_Time = 0.0f;

	};

}