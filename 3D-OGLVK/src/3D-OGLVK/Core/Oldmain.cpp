#include<filesystem>
namespace fs = std::filesystem;
#include<iostream>
					
#include"RendererGL.h"
#include"Window.h"
#include"Model.h"


#include"Camera.h"
#include"TimeStep.h"
#include"Input.h"
#include"GUI.h"


void InitOldProgram()
{
	Window window;
	window.InitWindow();

	RendererGL openGl;
	openGl.InitOpenGL(window);

	GUI gui;
	gui.InitGUI(window);

	TimeStep timeStep;
	timeStep.lastFrameTime = 0.0f;

	//FPS counter
	double currentTime = 0.0;
	double lastFrameTime = 0.0;
	double deltaTime = 0.0;
	unsigned int counter = 0;
	

	// Main while loop
	while (!glfwWindowShouldClose(window.glfwWindow))
	{
		//FPS counter
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastFrameTime;
		counter++;

		//Universal deltaTime kepping
		timeStep.currentTime = (float)glfwGetTime();
		timeStep.deltaTime = timeStep.currentTime - timeStep.lastFrameTime;
		timeStep.lastFrameTime = timeStep.currentTime;

		if (deltaTime >= 1.0 / 30.0)
		{
			std::string FPS = std::to_string((1.0 / deltaTime) * counter);
			std::string ms = std::to_string((deltaTime / counter) * 1000);
			std::string newTitle = "OpenGL :  " + FPS + ":FPS / " + ms + ":ms";
			glfwSetWindowTitle(window.glfwWindow, newTitle.c_str());
			lastFrameTime = currentTime;
			counter = 0;
		}

		
		openGl.Draw();
		openGl.HandelSwapBuffers(window);
		openGl.HandellGlfwEvents();
	}

	// Delete window & renderer before ending the program
	openGl.DeInitOpenGL();
	window.DeInitWindow();
	// Terminate GLFW before ending the program
	glfwTerminate();

	//return 0;
}



//int main()
//{	
//	Window window;
//	window.InitWindow();
//
//	TimeStep timeStep;
//	timeStep.lastFrameTime = 0.0f;
//
//	//FPS counter
//	double currentTime = 0.0;
//	double lastFrameTime = 0.0;
//	double deltaTime = 0.0;
//	unsigned int counter = 0;
//
//	// Generates Shader object using shaders default.vert and default.frag
//	Shader shaderProgram("default.vert", "default.frag");
//	
//	// Take care of all the light related things
//	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//	glm::vec3 lightPos = glm::vec3(0.0f, 1.0f, 0.5f);
//	glm::mat4 lightModel = glm::mat4(1.0f);
//	lightModel = glm::translate(lightModel, lightPos);
//
//	shaderProgram.Activate();
//	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
//
//	// Enables the Depth Buffer
//	glEnable(GL_DEPTH_TEST);
//	// Enable face-culling
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//	glFrontFace(GL_CCW);
//	//Enables culling of back faces
//	glDepthFunc(GL_LESS);
//	// Enables the Stencil Buffer
//	glEnable(GL_STENCIL_TEST);
//	// Sets rules for outcomes of stecil tests
//	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//
//	// Creates camera object
//	Camera camera;
//	camera.InitCamera(window.glfwWindow, 1280, 720, glm::vec3(0.0f, 0.2f, 1.0f));
//
//
//	Model model0("Assets/Meshes/bunny/scene.gltf");
//	
//	//Manipulate the object position/rotation
//	glm::vec3 modelPos0 = glm::vec3(0.0f, 0.0f, 0.0f);
//	glm::quat modelRot0 = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);
//	glm::vec3 modelScale0 = glm::vec3(3.0f, 3.0f, 3.0f);
//
//	modelRot0 = glm::angleAxis(3.14f, glm::vec3(0.0f, 0.0f, 1.0f));
//	//modelRot0 = glm::angleAxis(3.14f, glm::vec3(0.0f, 1.0f, 0.0f));
//
//	Model model1("Assets/Meshes/Cube/Cube.gltf");
//	glm::vec3 modelPos1 = glm::vec3(2.0f, 0.0f, 0.0f);
//	glm::quat modelRot1 = glm::quat(0.0f, 0.5f, 0.0f, 0.0f);
//	glm::vec3 modelScale1 = glm::vec3(1.0f, 1.0f, 1.0f);
//	//modelRot1 = glm::angleAxis(3.14f, glm::vec3(0.0f, 0.0f, 1.0f));
//	//modelRot1 = glm::angleAxis(3.14f, glm::vec3(0.0f, -1.0f, 0.0f));
//
//		
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window.glfwWindow))
//	{
//		//FPS counter
//		currentTime = glfwGetTime();
//		deltaTime = currentTime - lastFrameTime;
//		counter++;
//
//		//Universal deltaTime kepping
//		timeStep.currentTime = (float)glfwGetTime();
//		timeStep.deltaTime = timeStep.currentTime - timeStep.lastFrameTime;
//		timeStep.lastFrameTime = timeStep.currentTime;
//
//		if (deltaTime >= 1.0 / 30.0)
//		{
//			std::string FPS = std::to_string((1.0 / deltaTime) * counter);
//			std::string ms = std::to_string((deltaTime / counter) * 1000);
//			std::string newTitle = "OpenGL :  " + FPS + ":FPS / " + ms + ":ms";
//			glfwSetWindowTitle(window.glfwWindow, newTitle.c_str());
//			lastFrameTime = currentTime;
//			counter = 0;
//		}
//
//		// Specify the color of the background
//		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//		// Clean the back buffer and depth buffer
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//		
//		// Updates and exports the camera matrix to the Vertex Shader
//		camera.UpdateMatrix(60.0f, 0.1f, 100.0f);
//		//camera.CameraMovement(window);
//		camera.CameraMovement(window.glfwWindow);
//		camera.ProcessKeyboard(window.glfwWindow, timeStep.deltaTime);
//
//		// Make it so the stencil test always passes
//		glStencilFunc(GL_ALWAYS, 1, 0xFF);
//		// Enable modifying of the stencil buffer
//		glStencilMask(0xFF);
//
//		// Draw a model
//		model0.Draw(shaderProgram, camera, modelPos0, modelRot0, modelScale0);
//		model1.Draw(shaderProgram, camera, modelPos1, modelRot1, modelScale1);
//		
//		// Enable modifying of the stencil buffer
//		glStencilMask(0xFF);
//		// Clear stencil buffer
//		glStencilFunc(GL_ALWAYS, 0, 0xFF);
//		// Enable the depth buffer
//		glEnable(GL_DEPTH_TEST);
//
//		
//		// Swap the back buffer with the front buffer
//		glfwSwapBuffers(window.glfwWindow);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//
//
//	// Delete all the objects we've created
//	shaderProgram.Delete();
//
//	// Delete window before ending the program
//	glfwDestroyWindow(window.glfwWindow);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//
//	return 0;
//}
