#pragma once

class OpenGLInput
{
public:
	static void ProcessInput(GLFWwindow* window);
	static void ProcessInput(GLFWwindow* window, GLenum glKey, GLenum glPress, std::function<void()> func);
};
