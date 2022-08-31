#pragma once
#include "NurtEngine/Core.h"
#include "NurtEngine/Events/Event.h"

namespace NurtEngine {

	class NURTENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// When a layer is pushed on to the LayerStack
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}

		// When an event gets sent to the layer
		virtual void OnEvent(Event& event) {}

		//TODO: Add Enabling and Disabling of Layers

		inline const std::string& GetName() const { return m_DebugName; }
		
	protected:
		std::string m_DebugName;
	
	};

}