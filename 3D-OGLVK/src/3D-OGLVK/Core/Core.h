#pragma once

#ifdef OGLVK_PLATFORM_WINDOWS
	#ifdef OGLVK_BUILD_DLL
		#define OGLVK_API __declspec(dllexport)
	#else
		#define OGLVK_API __declspec(dllimport)
	#endif
#else 
	#error 3D-OGLVK only supports windows!
#endif // OGLVK_WINDOWS
