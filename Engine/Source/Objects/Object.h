#pragma once

class Object
{
public:
	void Init();

	void SetPosition(const glm::vec3& pos);
	void SetPosition(const float& x, const float& y, const float& z);
	glm::vec3 GetPosition();
	void SetRotation(const float& angle, const glm::vec3& rot);
	glm::vec3 GetRotation();
	void SetScale();
	glm::vec3 GetScale();

protected:
	glm::mat4 transform;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};