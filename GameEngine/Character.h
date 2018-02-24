#pragma once
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include "GameWindow.h"
#include "Object.h"
#include "Camera.h"


class Character : public Object
{
public:
	Character();
	Character(const char *);
	~Character();
	void update();
	void setMoveSpeed(float);
	void setRotationVLimit(float, float);
	void setRotationHLimit(float, float);

	int keyForward = GameWindow::keyW;
	int keyBack = GameWindow::keyS;
	int keyLeft = GameWindow::keyA;
	int keyRight = GameWindow::keyD;
protected:
	void move();

	Camera playerCamera;
	glm::vec3 position;
	glm::vec3 rotation;
	float moveSpeed = 1.f;
	glm::vec2 vRotLimit = glm::vec2(0, 360);
	glm::vec2 hRotLimit = glm::vec2(0, 360);
};