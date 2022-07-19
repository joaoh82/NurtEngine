#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern NurtEngine::Application* NurtEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = NurtEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif