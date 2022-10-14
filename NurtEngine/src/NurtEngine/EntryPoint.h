#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern NurtEngine::Application* NurtEngine::CreateApplication();

int main(int argc, char** argv)
{
	NurtEngine::Log::Init();
	NE_CORE_WARN("Initialized Log!");
	int a = 5;
	NE_INFO("Hello! Var={0}", a);

	auto app = NurtEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif