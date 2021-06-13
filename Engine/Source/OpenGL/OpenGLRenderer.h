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

	// Camera
	std::vector<float> viewPosition;
	float fieldOfView;
	
	// Object
	std::vector<float> objectPosition;
private:
	glm::mat4 view;
	glm::mat4 projection;
};
