#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace NurtEngine {
	class NURTENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Log Macros
#define NE_CORE_WARN(...)     ::NurtEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_INFO(...)     ::NurtEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_TRACE(...)    ::NurtEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NE_CORE_ERROR(...)    ::NurtEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_FATAL(...)    ::NurtEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define NE_WARN(...)          ::NurtEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_INFO(...)          ::NurtEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_TRACE(...)         ::NurtEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NE_ERROR(...)         ::NurtEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_FATAL(...)         ::NurtEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)