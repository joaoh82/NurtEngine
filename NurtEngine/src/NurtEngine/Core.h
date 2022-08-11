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

#ifdef NE_ENABLE_ASSERTS
#define NE_ASSERT(x, ...) { if(!(x)) { NE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NE_CORE_ASSERT(x, ...) { if(!(x)) { NE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define NE_ASSERT(x, ...)
#define NE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

