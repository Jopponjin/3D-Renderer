#include "Window.h"



Window::Window()
{
}

void Window::InitWindow()
{
	// Initialize GLFW
	glfwInit();

	//GLFW and OpenGl Hints.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4.6);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4.4);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	//glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

	// Assign pramary monitor and create a window.
	glfwMonitor = glfwGetPrimaryMonitor();
	glfwWindow = glfwCreateWindow(screenWidth, screenHeight, "OpenGL", NULL, NULL);

	// In case something goes wrong terminate the window and subsequent application.
	if (glfwWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		
		DeInitWindow();
	}

	// Introduce the window into the current context
	glfwMakeContextCurrent(glfwWindow);
	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// In this case the viewport goes from x = 0, y = 0, to x = 1280, y = 720
	glViewport(0, 0, 1280, 720);

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(glfwWindow);

	glfwSetFramebufferSizeCallback(glfwWindow, HandleFramebufferResize);

	if (glfwRawMouseMotionSupported()) 
	{
		glfwSetInputMode(glfwWindow, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	}

	std::cout << "InitWindow() called." << std::endl;
		
}

void Window::DeInitWindow()
{
	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
	exitApp = true;
}

void Window::HandleFramebufferResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


