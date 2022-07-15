#include <3D-OGLVK.h>


class Sandbox : public OGLVK::Application
{
public:
	Sandbox() 
	{

	}
	~Sandbox() 
	{

	}
};

OGLVK::Application* OGLVK::CreateApplication()
{
	return new Sandbox();
}


