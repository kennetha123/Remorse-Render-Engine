#pragma once
#include "OpenGLShader.h"
#include "OpenGLTexture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

private:
	OpenGLShader* shader;
	OpenGLShader* shader1;
	OpenGLTexture* texture;

public:
	void Render();
	void Draw();

private:
	unsigned int VBO[2];
	unsigned int VAO[2];
	unsigned int EBO;

	glm::mat4 transform;
};
