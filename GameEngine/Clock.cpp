#include "stdafx.h"
#include "Clock.h"

float Clock::oldTime = float(glfwGetTime());
float Clock::deltaTime = 0;


Clock::Clock()
{
}


Clock::~Clock()
{
}



void Clock::update()
{
	double newTime = glfwGetTime();
	deltaTime = newTime - oldTime;
	oldTime = newTime;
}