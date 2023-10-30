#pragma once

#ifdef GR_WINDOWS

#include "Application.h"

extern Gripper::Application* Gripper::CreateApplication();

int main(int argc, char** argv)
{
	Gripper::Log::Init();
	auto app = Gripper::CreateApplication();
	app->Run();
	delete app;
}

#endif