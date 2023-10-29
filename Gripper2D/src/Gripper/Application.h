#pragma once

#include "Core.h"

namespace Gripper
{
	class GR_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}