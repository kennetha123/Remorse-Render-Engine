#pragma once
#include <fstream>
#include <sstream>
#include <string>

class OpenGLShader
{
public:
	OpenGLShader();
	~OpenGLShader();
	void ShaderAssert(unsigned int shader);
	
public:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

};