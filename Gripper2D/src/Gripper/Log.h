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