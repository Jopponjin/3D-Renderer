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

	int screenWidth = 1280;
	int screenHeight = 720;

	int virtualWidth = 0;
	int virtualHeight = 0;


	GLFWwindow* glfwWindow;
	GLFWmonitor* glfwMonitor;

	// Struct to hold renderer info
	struct GLRendererInfo 
	{
		GLint rendererID;       // RendererID number
		GLint accelerated;      // Whether Hardware accelerated
		GLint online;           // Whether renderer (/GPU) is onilne
		GLint virtualScreen;    // Virtual screen number
		GLint videoMemoryMB;
		GLint textureMemoryMB;
		const GLubyte* vendor;
	};
};

#endif
