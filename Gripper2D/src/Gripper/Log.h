#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Gripper
{
	class GR_API Log
	{
	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetCorelogger() { return s_CoreLogger; };
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#if defined(GR_DEBUG) || defined(GR_RELEASE)

#define GR_CORE_INFO(...) Gripper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GR_CORE_WARN(...) Gripper::Log::GetCorelogger()->warn(__VA_ARGS__)
#define GR_CORE_TRACE(...) Gripper::Log::GetCorelogger()->trace(__VA_ARGS__)
#define GR_CORE_ERROR(...) Gripper::Log::GetCorelogger()->error(__VA_ARGS__)
#define GR_CORE_CRITICAL(...) Gripper::Log::GetCorelogger()->critical(__VA_ARGS__)

#define GR_INFO(...) Gripper::Log::GetClientLogger()->info(__VA_ARGS__)
#define GR_WARN(...) Gripper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GR_TRACE(...) Gripper::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GR_ERROR(...) Gripper::Log::GetClientLogger()->error(__VA_ARGS__)
#define GR_CRITICAL(...) Gripper::Log::GetClientLogger()->critical(__VA_ARGS__)

#else

#define GR_CORE_INFO(...)
#define GR_CORE_WARN(...)
#define GR_CORE_TRACE(...)
#define GR_CORE_ERROR(...)
#define GR_CORE_CRITICAL(...)

#define GR_INFO(...)
#define GR_WARN(...)
#define GR_TRACE(...)
#define GR_ERROR(...)
#define GR_CRITICAL(...)

#endif