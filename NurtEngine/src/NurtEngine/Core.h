#pragma once

#ifdef NE_PLATFORM_WINDOWS
	#ifdef NE_BUILD_DLL
		#define NURTENGINE_API __declspec(dllexport)
	#else
		#define NURTENGINE_API __declspec(dllimport)
	#endif
#else
	#error NurtEngine only support Windows for now!
#endif