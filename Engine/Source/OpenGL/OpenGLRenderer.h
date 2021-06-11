#pragma once
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
#include "Objects/GameObject.h"


class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

private:
	GameObject gameObject;
public:
	void Render();
	void Draw();
};
