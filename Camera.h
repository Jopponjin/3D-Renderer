#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include <GL/GL.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"
#include"TimeStep.h"

class Camera
{
public:

	// Stores the main vectors of the camera
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 cameraRotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraRight = glm::vec3(-1.0f, 0.0f, 0.0f);

	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 worldUp = glm::vec3(0.0f, 0.0f, 0.0f);

	float lastX;
	float lastY;

	// euler Angles
	float yaw;
	float pitch;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 3.0f;
	float sensitivity = 50.0f;
	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	// Stores the width and height of the window
	int width;
	int height;

	// Camera constructor to set up initial values
	void InitCamera(GLFWwindow* window, int width, int height, glm::vec3 position);

	// Updates and exports the camera matrix to the Vertex Shader
	void UpdateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void Matrix(Shader& shader, const char* uniform);

	void ProcessKeyboard(GLFWwindow* window, float deltaTime);

	// Handles camera inputs
	void CameraMovement(GLFWwindow* window);
	void CameraLook(GLFWwindow* window);


};
#endif