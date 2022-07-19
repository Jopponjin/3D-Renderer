#pragma once

#include <memory>

#include "Core.h"
#include "spdlog.h"

namespace OGLVK
{
	class OGLVK_API Log
	{
	public:
		static void InitLog();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}



