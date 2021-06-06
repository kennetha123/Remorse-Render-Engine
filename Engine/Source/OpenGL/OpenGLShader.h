#pragma once
#include <fstream>
#include <sstream>
#include <string>

class OpenGLShader
{
public:
	OpenGLShader(const char* vertexPath, const char* fragmentPath);
	~OpenGLShader();

public:
	void use();
	void SetUniformBool(const std::string& name, bool value) const;
	void SetUniformInt(const std::string& name, int value) const;
	void SetUniformFloat(const std::string& name, float value) const;
private:
	void ShaderAssert(unsigned int shader);
	
public:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

};