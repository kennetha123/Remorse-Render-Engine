#pragma once
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

private:
	OpenGLShader* shader;
	OpenGLTexture* texture;

public:
	void Render();
	void Draw();

private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;


};
