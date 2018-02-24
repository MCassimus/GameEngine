#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>

class Clock
{
public:
	Clock();
	~Clock();
	void update();
	static float deltaTime;
private:
	static float oldTime;
};