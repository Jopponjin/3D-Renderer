#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "Camera.h"

class Window
{
public:
	Window();

	void InitWindow();
	void DeInitWindow();
	//Callback function when  the user changes the window size, affects glViewport.
	static void HandleFramebufferResize(GLFWwindow* window, int width, int height);

	bool exitApp;

	int width = 1280;
	int height = 720;

	GLFWwindow* glfwWindow;
	GLFWmonitor* glfwMonitor;
};

#endif
