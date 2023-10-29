#include "Gripper2D.h"

class Sandbox : public Gripper::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Gripper::Application* Gripper::CreateApplication()
{
	return new Sandbox();
}