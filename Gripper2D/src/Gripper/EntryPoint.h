#pragma once

#ifdef GR_WINDOWS

#include "Application.h"

extern Gripper::Application* Gripper::CreateApplication();

int main(int argc, char** argv)
{
	Gripper::Log::Init();
	GR_CORE_WARN("Initalized Logger!");
	int a = 5;
	GR_INFO("Hello, world! Var = {0}", a);
	auto app = Gripper::CreateApplication();
	app->Run();
	delete app;
}

#endif