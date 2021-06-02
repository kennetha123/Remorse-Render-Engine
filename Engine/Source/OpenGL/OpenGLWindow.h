#pragma once
#include "OpenGL/OpenGLInput.h"
#include "OpenGL/OpenGLRenderer.h"
class OpenGLWindow
{
public:
	OpenGLWindow(unsigned int&& width, unsigned int&& height, std::string&& title);
	~OpenGLWindow();

	void UpdateWindow();

private:
	GLFWwindow* window;
	OpenGLInput input;
	OpenGLRenderer* render;
};

