#include "grpch.h"
#include "Application.h"
#include "Gripper/Log.h"
#include "Gripper/Events/ApplicationEvent.h"


namespace Gripper
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowFocusEvent e;
		GR_INFO(e);
		while (true);
	}
}