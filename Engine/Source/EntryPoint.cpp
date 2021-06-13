#include "rrepch.h"
#include "OpenGL/OpenGLWindow.h"

int main()
{
	OpenGLWindow* window = new OpenGLWindow(1280, 720, "Remorse Render Engine");
	window->UpdateWindow();
	delete window;
}