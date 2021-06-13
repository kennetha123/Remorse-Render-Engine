#pragma once
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
#include "Objects/GameObject.h"

class GameObject;

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

public:
	void Draw();

private:
	OpenGLShader* shader;
	std::vector<GameObject> gameObject;
	GameObject go;
	std::vector<glm::vec3> cubePositions;

private:
	glm::mat4 view;
	glm::mat4 projection;
};
