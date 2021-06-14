#include "rrepch.h"
#include "Camera.h"

Camera::Camera() :
	fieldOfView(45.0f), shader("Shader/triangle.vert", "Shader/triangle.frag")
{
	// Init position
	SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));

	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraForward = glm::normalize(position - cameraTarget);
	
	// world up when init
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	
	cameraRight = glm::normalize(glm::cross(up, cameraForward));

	cameraUp = glm::cross(cameraForward, cameraRight);

}

Camera::~Camera()
{
}

void Camera::Draw()
{
	projection = glm::perspective(glm::radians(fieldOfView), 1280.0f / 720.0f, 0.1f, 100.0f);
	shader.SetUniformMat4("projection", projection);

	view = glm::lookAt(position, cameraForward + position, cameraUp);
	shader.SetUniformMat4("view", view);
}
