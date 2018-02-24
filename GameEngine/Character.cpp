#include "stdafx.h"
#include "Character.h"


Character::Character() : Object()
{
	setRotationVLimit(-70, 70);
}


Character::Character(const char * file) : Object(file)
{
	setRotationVLimit(-70, 70);

}


Character::~Character()
{
}


void Character::update()
{
	move();//move character as needed
	printf("updating character\n");
	printf("chposx%f chposy%f chposz%f\n", position.x, position.y, position.z);
	printf("chrotx%f chroty%f chrotz%f\n", rotation.x, rotation.y, rotation.z);
	playerCamera.update();
}


void Character::setMoveSpeed(float newSpeed)
{
	moveSpeed = newSpeed;
}


void Character::setRotationVLimit(float min, float max)
{
	vRotLimit = glm::vec2(min, max);
	playerCamera.setRotationVLimit(min, max);
}


void Character::setRotationHLimit(float min, float max)
{
	hRotLimit = glm::vec2(min, max);
	playerCamera.setRotationHLimit(min, max);
}


void Character::move()
{
	glm::vec3 moveDelta = glm::vec3(0, 0, 0);
	glm::vec3 rotDelta = glm::vec3(0, 0, 0);

	//update rotation
	rotDelta.x += float(GameWindow::mouseDelta.y * Clock::deltaTime);
	rotDelta.y += float(GameWindow::mouseDelta.x * Clock::deltaTime);

	//move forward
	if (GameWindow::keyPressed(keyForward) || GameWindow::keyHeld(keyForward))
		moveDelta.z += moveSpeed * GameWindow::clock.deltaTime;
	//move back
	if (GameWindow::keyPressed(keyBack) || GameWindow::keyHeld(keyBack))
		moveDelta.z -= moveSpeed * GameWindow::clock.deltaTime;
	//move left
	if (GameWindow::keyPressed(keyLeft) || GameWindow::keyHeld(keyLeft))
		moveDelta.x += moveSpeed * GameWindow::clock.deltaTime;
	//move right
	if (GameWindow::keyPressed(keyRight) || GameWindow::keyHeld(keyRight))
		moveDelta.x -= moveSpeed * GameWindow::clock.deltaTime;

	if (rotation.y == 360.f && rotDelta.y > 0.f)//max of circle with positve rotation
		rotation.y = 0.f;//set to min for smooth transition with math
	else if (rotation.y == 0 && rotDelta.y < 0.f && hRotLimit.y >= 360.f)//min of circle with neg rotation with full range
		rotation.y = 360.f;//set to max polar angle for smooth transition with math
	
	//apply deltas to player global position
	rotation.y = glm::clamp(rotation.y + rotDelta.y, hRotLimit.x, hRotLimit.y);
	//rotate move delta on the up axis to convert move deltas to be in relation to local forward & right axis
	moveDelta = glm::rotate(moveDelta, rotation.y, glm::vec3(0, 1, 0));
	position += moveDelta;
	
	//move camera with character
	playerCamera.move(moveDelta, rotDelta);
}