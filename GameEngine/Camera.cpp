#include "stdafx.h"
#include "Camera.h"
#include "Clock.h"
#include "GameWindow.h"
#include <cmath>


Camera::Camera()
{
	
}


Camera::~Camera()
{
}


void Camera::update()
{
	printf("updating camera\n");
	
	//calc look at pos in relation to the position of the character
	target.x = sin(rotation.y) * cameraDistance;
	target.y = sin(rotation.x) * cameraDistance;
	target.z = cos(rotation.y) * cameraDistance;
 	target += position;

	printf("camposx%f camposy%f camposz%f\n", position.x, position.y, position.z);
	printf("camptgtosx%f camtgtposy%f camtgtposz%f\n", target.x, target.y, target.z);
	printf("camrotx%f camroty%f camrotz%f\n", rotation.x, rotation.y, rotation.z);
}


void Camera::move(glm::vec3 moveDelta, glm::vec3 rotDelta)
{
	if (rotation.y == 360.f && rotDelta.y > 0.f)//max of circle with positve rotation
		rotation.y = 0.f;//set to min for smooth transition with math
	else if (rotation.y == 0 && rotDelta.y < 0.f && hRotLimit.y >= 360.f)//min of circle with neg rotation with full range
		rotation.y = 360.f;//set to max polar angle for smooth transition with math
	
	position += moveDelta;
	rotation += rotDelta;

	//apply rotation clamping
	rotation.y = glm::clamp(rotation.y, hRotLimit.x, hRotLimit.y);
	rotation.x = glm::clamp(rotation.x, vRotLimit.x, vRotLimit.y);
}


void Camera::setRotationVLimit(float min, float max)
{
	vRotLimit = glm::vec2(min, max);
}


void Camera::setRotationHLimit(float min, float max)
{
	hRotLimit = glm::vec2(min, max);
}