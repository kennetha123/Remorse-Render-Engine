#pragma once
#include <fstream>
#include <string>
#include <sstream>
class OpenGLRenderer
{
public:
	void Render();
	void Draw();
	void ShaderAssert(unsigned int shader);
private:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
};
