#pragma once
#include "OpenGL/OpenGLBuffer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	void Draw();

public:
	glm::mat4 transform;

private:
	OpenGLShader* shader;
	OpenGLTexture* texture;

private:
	OpenGLVertexBuffer vertexBuffer;
	OpenGLIndexBuffer indexBuffer;

	unsigned int vao;

};