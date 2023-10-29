#pragma once

#ifdef GR_WINDOWS
	#ifdef GR_BUILD_DLL
		#define GR_API __declspec(dllexport)
	#else
		#define GR_API __declspec(dllimport)
	#endif
#else
	#error Gripper2D only supported on windows!
#endif