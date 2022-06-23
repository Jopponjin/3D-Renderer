#ifndef INPUT_CLASS_H
#define INPUT_CLASS_H

#include<iostream>
#include<string>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

class Input 
{
public:

	Input();

	int axisVector;

	void InitInput(GLFWwindow* window);

	static void HandelKeyInputs(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void HandelMouseInputs(GLFWwindow* window, double xPos, double yPos);

	static int GetAxis(GLFWwindow* window, std::string axis);
	
};

#endif