#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenGL/OpenGLInput.h"

class OpenGLWindow
{
public:
	OpenGLWindow(unsigned int&& width, unsigned int&& height, std::string&& title);
	~OpenGLWindow();

	void UpdateWindow();

private:
	GLFWwindow* window;
	OpenGLInput input;
};

