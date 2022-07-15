#pragma once

#include "Core.h"

namespace OGLVK
{
	class OGLVK_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();
}



