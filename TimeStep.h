#ifndef TIME_CLASS_H
#define TIME_CLASS_H

#include<GLFW/glfw3.h>
#include<chrono>

class TimeStep
{
public:

	float GetSeconds() const { return deltaTime;  }
	float GetMiliSeconds() const { return deltaTime * 1000;  }

	float currentTime;
	float deltaTime;
	float lastFrameTime = 0.0f;

private:
	float stepTime;
	
};


#endif