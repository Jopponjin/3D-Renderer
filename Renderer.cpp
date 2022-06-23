#include "Renderer.h"



//// Vertices coordinates
//GLfloat vertices[] =
//{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
//	-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
//	-1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
//	 1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
//	 1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 2, 3
//};
//
//GLfloat lightVertices[] =
//{ //     COORDINATES     //
//	-0.1f, -0.1f,  0.1f,
//	-0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f, -0.1f,
//	 0.1f, -0.1f,  0.1f,
//	-0.1f,  0.1f,  0.1f,
//	-0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f, -0.1f,
//	 0.1f,  0.1f,  0.1f
//};
//
//GLuint lightIndices[] =
//{
//	0, 1, 2,
//	0, 2, 3,
//	0, 4, 7,
//	0, 7, 3,
//	3, 7, 6,
//	3, 6, 2,
//	2, 6, 5,
//	2, 5, 1,
//	1, 5, 4,
//	1, 4, 0,
//	4, 5, 6,
//	4, 6, 7
//};
//
//
//
//
//Renderer::Renderer()
//{
//	std::cout << "Renderer() called." << std::endl;
//}
//
//void Renderer::InitRenderer()
//{
//
//	shaderProgram = Shader();
//	lightShader = Shader();
//	textureTest = Texture();
//
//	VAO1 = VAO();
//	VBO1 = VBO();
//	EBO1 = EBO();
//
//	lightVAO = VAO();
//	lightEBO = EBO();
//	lightVBO = VBO();
//	
//	// Generates Shader object using shaders default.vert and default.frag
//	shaderProgram.SubmitShaderData("default.vert", "default.frag");
//	// Generates Vertex Array Object and binds it.
//	VAO1.Bind();
//	// Generates Vertex Buffer Object and links it to vertices.
//	VBO1.InitVBO(vertices, sizeof(vertices));
//	// Generates Element Buffer Object and links it to indices.
//	EBO1.InitEBO(indices, sizeof(indices));
//	// Links VBO to VAO.
//	VAO1.LinkAttribute(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//	VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//	VAO1.LinkAttribute(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//	VAO1.LinkAttribute(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//	VAO1.LinkAttribute(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//	// Unbind all to prevent accidentally modifying them
//	VAO1.Unbind();
//	VBO1.Unbind();
//	EBO1.Unbind();
//
//	// Shader for light cube
//	lightShader.SubmitShaderData("light.vert", "light.frag");
//	// Generates Vertex Array Object and binds it
//	lightVAO.Bind();
//	// Generates Vertex Buffer Object and links it to vertices
//	lightVBO.InitVBO(lightVertices, sizeof(lightVertices));
//	// Generates Element Buffer Object and links it to indices
//	lightEBO.InitEBO(lightIndices, sizeof(lightIndices));
//	// Links VBO attributes such as coordinates and colors to VAO
//	lightVAO.LinkAttribute(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
//	// Unbind all to prevent accidentally modifying them
//	lightVAO.Unbind();
//	lightVBO.Unbind();
//	lightEBO.Unbind();
//
//
//	lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//	lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
//	lightModel = glm::mat4(1.0f);
//	lightModel = glm::translate(lightModel, lightPos);
//
//	pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
//	pyramidModel = glm::mat4(1.0f);
//	pyramidModel = glm::translate(pyramidModel, pyramidPos);
//
//
//	lightShader.Activate();
//	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
//	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//
//	shaderProgram.Activate();
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
//	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
//	//Texture pahting.
//	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
//	std::string texPath = "/Assets/Textures/";
//
//	// Texture.
//	textureTest.SubmitTextureData("ToastLordV2.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
//	textureTest.texUnit(shaderProgram, "tex0", 0);
//	// Texture Specular.
//	//textureTest.SubmitTextureData("ToastLordV2.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
//	//textureTest.texUnit(shaderProgram, "tex0", 0);
//
//	// Enables the Depth Buffer.
//	glEnable(GL_DEPTH_TEST);
//
//	std::cout << "InitRenderer() called." << std::endl;
//}
//
//void Renderer::Draw(Camera camera)
//{
//	// Specify the color of the background.
//	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//	// Clean the back buffer and assign the new color to it.
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	camera.UpdateMatrix(60.0f, 0.1f, 100.0f);
//
//	// Tells OpenGL which Shader Program we want to use
//	shaderProgram.Activate();
//	// Exports the camera Position to the Fragment Shader for specular lighting
//	glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.cameraPosition.x, camera.cameraPosition.y, camera.cameraPosition.z);
//	// Export the camMatrix to the Vertex Shader of the pyramid
//	camera.Matrix(shaderProgram, "camMatrix");
//	// Bind the VAO so OpenGL knows to use i.
//	textureTest.Bind();
//	// Bind the VAO so OpenGL knows to use it.
//	VAO1.Bind();
//	// Draw primitives, number of indices, datatype of indices, index of indices
//	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//	// Tells OpenGL which Shader Program we want to use
//	lightShader.Activate();
//	// Export the camMatrix to the Vertex Shader of the light cube
//	camera.Matrix(lightShader, "camMatrix");
//	// Bind the VAO so OpenGL knows to use it
//	lightVAO.Bind();
//	// Draw primitives, number of indices, datatype of indices, index of indices
//	glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//	
//}
//
//
//
//void Renderer::DeInitRenderer()
//{
//	std::cout << "DeInitRenderer() called." << std::endl;
//
//	// Delete all the objects we've created.
//	VAO1.Delete();
//	VBO1.Delete();
//	EBO1.Delete();
//	textureTest.Delete();
//	shaderProgram.Delete();
//
//	lightVAO.Delete();
//	lightVBO.Delete();
//	lightEBO.Delete();
//	lightShader.Delete();
//}

