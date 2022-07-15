#pragma once

#ifdef OGLVK_PLATFORM_WINDOWS

extern OGLVK::Application* OGLVK::CreateApplication();

int main(int argc, char** argv)
{
	auto app = OGLVK::CreateApplication();
	app->Run();
	delete app;
	return 0;
}


#endif // OGLVK_PLATFORM_WINDOWS




