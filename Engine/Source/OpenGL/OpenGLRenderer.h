#pragma once
#include "OpenGLShader.h"

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

public:
	OpenGLShader* shader;

public:
	void Render();
	void Draw();

private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	unsigned int texture;
	unsigned int texture1;

};
