#include "rrepch.h"
#include "OpenGLInput.h"

void OpenGLInput::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void OpenGLInput::ProcessInput(GLFWwindow* window, GLenum glKey, GLenum glPress, std::function<void()> func)
{
	if (glfwGetKey(window, glKey) == glPress)
	{
		func();
	}
}
