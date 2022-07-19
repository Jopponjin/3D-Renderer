#pragma once

#include "Core.h"
#include <iostream>

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



