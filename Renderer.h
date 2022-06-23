#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H
#include<filesystem>
namespace fs = std::filesystem;

#include<iostream>

#include<stb/stb_image.h>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


#include"Window.h"
#include"Camera.h"
#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


class Renderer
{
public:
	Renderer();

	void InitRenderer();
	void Draw(Camera camera);
	void DeInitRenderer();

private:
	Window window;

	Shader shaderProgram;
	Shader lightShader;
	Texture textureTest;

	VAO VAO1, lightVAO;
	VBO VBO1, lightVBO;
	EBO EBO1, lightEBO;

	glm::vec4 lightColor = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
};

#endif
