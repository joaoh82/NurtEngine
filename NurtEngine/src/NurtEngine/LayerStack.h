#pragma once

#include "NurtEngine/Core.h"
#include "Layer.h"

#include <vector>

namespace NurtEngine {
	
	/// <summary>
	/// The LayerStack is a wrapper around the stack of layers (m_Layers)
	/// </summary>
	class NURTENGINE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		// The reason this is not actually a stack is because we can push layers in the middle of it
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}