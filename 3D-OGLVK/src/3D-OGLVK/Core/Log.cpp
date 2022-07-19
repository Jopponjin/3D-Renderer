#include "Log.h"

namespace OGLVK
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::InitLog()
	{
	}
}


