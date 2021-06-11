#pragma once
#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLTexture.h"

class OpenGLVertexBuffer
{
public:
	OpenGLVertexBuffer();
	~OpenGLVertexBuffer();

public:
	void SetData(void* vertices, const unsigned int& vertSize);
	void Bind() const;
	void Unbind() const;

private:
	unsigned int render_ID;
};

class OpenGLIndexBuffer
{
public:
	OpenGLIndexBuffer();
	~OpenGLIndexBuffer();

public:
	void SetData(void* indices, const unsigned int& indiSize);
	void Bind() const;
	void Unbind() const;

private:
	unsigned int render_ID;

};