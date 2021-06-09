#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "glm/glm.hpp"

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
	void SetUniformVec2(const std::string& name, const glm::vec2& value) const;
	void SetUniformVec2(const std::string& name, float x, float y) const;
	void SetUniformVec3(const std::string& name, const glm::vec3& value) const;
	void SetUniformVec3(const std::string& name, float x, float y, float z) const;
	void SetUniformVec4(const std::string& name, const glm::vec4& value) const;
	void SetUniformVec4(const std::string& name, float x, float y, float z, float w) const;
	
	void SetUniformMat2(const std::string& name, const glm::mat2& value) const;
	void SetUniformMat3(const std::string& name, const glm::mat3& value) const;
	void SetUniformMat4(const std::string& name, const glm::mat4& value) const;

private:
	void ShaderAssert(GLuint shader, const std::string& type);
	
public:
	unsigned int shaderProgram;
	unsigned int vertexShader;
	unsigned int fragmentShader;

};