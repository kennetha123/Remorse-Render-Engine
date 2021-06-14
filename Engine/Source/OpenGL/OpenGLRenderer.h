#pragma once
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
#include "Objects/GameObject.h"
#include "Objects/Camera/Camera.h"
class GameObject;

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

public:
	void Draw();

private:
	// temporary shader
	OpenGLShader* shader;

	// temp object. Idk why if using object
	// temp in the TU it cause crashed.
	// neither the glGetError caught the error
	// and I will investigate that in the further notice.
	GameObject go;

	std::vector<GameObject> gameObject;
	std::vector<glm::vec3> cubePositions;

	// Camera
	Camera camera;
	
	// Object
	std::vector<float> objectPosition;
};
