#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <filesystem>
namespace fs = std::filesystem;

#include <iostream>

#include <stb/stb_image.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Window.h"
#include "Camera.h"
#include "Texture.h"
#include "Model.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


class RendererGL
{
public:
	RendererGL();

	void InitOpenGL(Window window);

	void HandelSwapBuffers(Window window);
	void HandellGlfwEvents();

	void Draw();
	void DeInitOpenGL();

	int width = 1280;
	int height = 720;

private:
	Camera camera;

	Shader shaderProgram;


	//TODO: make an entity class to make handling models 
	Model model;

	glm::vec3 modelPos0 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::quat modelRot0 = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);
	glm::vec3 modelScale0 = glm::vec3(3.0f, 3.0f, 3.0f);

	

	glm::vec3 modelPos1 = glm::vec3(2.0f, 0.0f, 0.0f);
	glm::quat modelRot1 = glm::quat(0.0f, 0.5f, 0.0f, 0.0f);
	glm::vec3 modelScale1 = glm::vec3(1.0f, 1.0f, 1.0f);
};

#endif
