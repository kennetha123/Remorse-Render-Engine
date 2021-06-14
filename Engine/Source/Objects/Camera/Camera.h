#pragma once
#include "Objects/Object.h"
#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLInput.h"

class Camera : public Object
{
public:
	Camera();
	~Camera();

	void Draw();
	void Input(GLFWwindow* window);

public:
	float fieldOfView;

private:
	OpenGLShader shader;

private:
	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 cameraTarget;
	glm::vec3 cameraForward;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

};