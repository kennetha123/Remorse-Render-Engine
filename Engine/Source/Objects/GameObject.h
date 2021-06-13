#pragma once
#include "Object.h"
#include "OpenGL/OpenGLBuffer.h"

class GameObject : public Object
{
public:
	GameObject();
	~GameObject();

public:
	void Draw();

public:
	OpenGLTexture texture;
	OpenGLShader shader;

private:
	OpenGLVertexBuffer vertexBuffer;
	OpenGLIndexBuffer indexBuffer;
	unsigned int vao;

};