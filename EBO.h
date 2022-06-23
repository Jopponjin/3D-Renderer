#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>
#include<vector>

class EBO
{
public:

	EBO(std::vector<GLuint>& indices);

	// Function that generates a Elements Buffer Object and links it to indices
	void InitEBO(GLuint* indices, GLsizeiptr size);

	// Binds the EBO
	void Bind();
	// Unbinds the EBO
	void Unbind();
	// Deletes the EBO
	void Delete();

	// ID reference of Elements Buffer Object
	GLuint ID = 0;
};

#endif