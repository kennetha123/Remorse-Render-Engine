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
	OpenGLTexture* texture;

public:
	void Render();
	void Draw();

private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	glm::mat4 transform;
};
