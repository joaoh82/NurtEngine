#include <NurtEngine.h>

class ExampleLayer : public NurtEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		NE_INFO("ExampleLayer::Update");
	}

	void OnEvent(NurtEngine::Event& event) override
	{
		NE_TRACE("{0}", event);
	}

};

class Sandbox : public NurtEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

NurtEngine::Application* NurtEngine::CreateApplication()
{
	return new Sandbox();
}