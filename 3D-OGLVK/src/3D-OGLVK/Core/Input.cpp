#include "Input.h"



Input::Input()
{

}

void Input::InitInput(GLFWwindow* window)
{
	glfwSetCursorPosCallback(window, HandelMouseInputs);
	glfwSetKeyCallback(window, HandelKeyInputs);
}

void Input::HandelKeyInputs(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	/*if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		std::cout << "Input: key = W pressed." << std::endl;
		
	}
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		std::cout << "Input: key = S pressed." << std::endl;
	}
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		std::cout << "Input: key = A pressed." << std::endl;
	}
	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		std::cout << "Input: key = D pressed." << std::endl;
	}*/
}

void Input::HandelMouseInputs(GLFWwindow* window, double xPos, double yPos)
{
	
}



int Input::GetAxis(GLFWwindow* window, std::string axis)
{
	if (axis == "Horizontal") return -1;
	if (axis == "Vertical") return 1;

	return 0;
}
