#pragma once
#include <gl\glew.h>
#include <glm\glm.hpp>

//https://learnopengl.com/Getting-started/Camera


class Camera
{
public:
	Camera();
	~Camera();
	void update();
	void move(glm::vec3, glm::vec3);
	void setRotationVLimit(float, float);
	void setRotationHLimit(float, float);
protected:
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 rotation;
	float cameraDistance = 1.f;
	glm::vec2 vRotLimit = glm::vec2(0, 360);
	glm::vec2 hRotLimit = glm::vec2(0, 360);
};