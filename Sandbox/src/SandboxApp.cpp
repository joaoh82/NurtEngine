#include <NurtEngine.h>

class Sandbox : public NurtEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

NurtEngine::Application* NurtEngine::CreateApplication()
{
	return new Sandbox();
}