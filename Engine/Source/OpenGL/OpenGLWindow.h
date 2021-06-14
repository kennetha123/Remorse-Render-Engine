#pragma once
#include "OpenGL/OpenGLInput.h"
#include "OpenGL/OpenGLRenderer.h"
#include "ImGui/ImGui_Main.h"

class OpenGLWindow
{
public:
	OpenGLWindow(unsigned int&& width, unsigned int&& height, std::string&& title);
	~OpenGLWindow();

	void UpdateWindow();

private:
	GLFWwindow* window;
	ImGui_Main imgui;
	OpenGLRenderer* render;
};

