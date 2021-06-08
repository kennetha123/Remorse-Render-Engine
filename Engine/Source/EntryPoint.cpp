#include "rrepch.h"
#include "OpenGL/OpenGLWindow.h"

int main()
{
	OpenGLWindow* window = new OpenGLWindow(1366, 1024, "Remorse Render Engine");
	window->UpdateWindow();
	delete window;
}