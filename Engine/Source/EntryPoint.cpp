#include "rrepch.h"
#include "OpenGL/OpenGLWindow.h"

int main()
{
	OpenGLWindow* window = new OpenGLWindow(1280, 720, "Test");
	window->UpdateWindow();
	delete window;
}