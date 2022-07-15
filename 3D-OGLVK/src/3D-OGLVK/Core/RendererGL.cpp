#include "RendererGL.h"




RendererGL::RendererGL()
{
	
}



void RendererGL::InitOpenGL(Window window)
{
	std::cout << "Renderer() called." << std::endl;

	// Generates Shader object using shaders default.vert and default.frag
	shaderProgram = Shader();
	shaderProgram.SubmitShaderData("default.vert", "default.frag");

	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 1.0f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);
	// Enable face-culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Enables culling of back faces
	glDepthFunc(GL_LESS);
	// Enables the Stencil Buffer
	glEnable(GL_STENCIL_TEST);
	// Sets rules for outcomes of stecil tests
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	camera = Camera();
	camera.InitCamera(window.glfwWindow, width, height, glm::vec3(0.0f, 0.2f, 1.0f));

	model = Model();

	model.StreamModel("Assets/Meshes/bunny/scene.gltf");

	//Manipulate the object position/rotation


	modelRot0 = glm::angleAxis(3.14f, glm::vec3(0.0f, 0.0f, 1.0f));
	
	//modelRot0 = glm::angleAxis(3.14f, glm::vec3(0.0f, 1.0f, 0.0f));

	model.StreamModel("Assets/Meshes/Cube/Cube.gltf");

}

void RendererGL::HandelSwapBuffers(Window window)
{
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window.glfwWindow);
}

void RendererGL::HandellGlfwEvents()
{
	// Take care of all GLFW events
	glfwPollEvents();
}

void RendererGL::Draw()
{
	//Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Updates and exports the camera matrix to the Vertex Shader
	camera.UpdateMatrix(60.0f, 0.1f, 100.0f);

	// Make it so the stencil test always passes
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	// Enable modifying of the stencil buffer
	glStencilMask(0xFF);

	//TODO: Add models pass here

	// Enables trancprancy blend
	glEnable(GL_BLEND);

	// Draw a model
	model.Draw(shaderProgram, camera, modelPos0, modelRot0, modelScale0);
	
	// Disables trancprancy blend
	glDisable(GL_BLEND);
	// Enable modifying of the stencil buffer
	glStencilMask(0xFF);
	// Clear stencil buffer
	glStencilFunc(GL_ALWAYS, 0, 0xFF);
	// Enable the depth buffer
	glEnable(GL_DEPTH_TEST);
}

void RendererGL::DeInitOpenGL()
{


	std::cout << "DeInitRenderer() called." << std::endl;
}

