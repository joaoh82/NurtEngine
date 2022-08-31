#include "nepch.h"
#include "LayerStack.h"

namespace NurtEngine {

	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{	
		// LayerStack is owned by the Application and it will be deallocated when the Application shuts down
		// Layers are intended to live throughout the lifetime of the application
		for (Layer* layer : m_Layers)
			delete layer; // Destroying a layer
	}

	// Layers get pushed into the first half of the list
	// Layer always gets pushed before OverLays
	void LayerStack::PushLayer(Layer* layer)
	{
		// Layers are owned by the LayerStack
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	// OverLayers get pushed into the second half of the list
	// The reason why is OverLays you always want to render last
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// When we pop a layer we don't really lose it.
		// If you pop a Layer temporarily by some reason
		// You always push it back in because the Layer is not really destroyed
		// Until the Application gets destroyed.
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

}