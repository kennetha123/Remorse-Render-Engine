#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class OpenGLDebugger
{
public:

	static GLenum glCheckError(const char* file, int line);
};