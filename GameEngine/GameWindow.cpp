#include "stdafx.h"
#include "GameWindow.h"

GLFWwindow * GameWindow::window = nullptr;
glm::dvec2 GameWindow::mousePos = glm::dvec2(0, 0);
glm::dvec2 GameWindow::mouseDelta = glm::dvec2(0, 0);
Clock GameWindow::clock = Clock();


GameWindow::GameWindow()
{
	#pragma region initGlfw
	if (!glfwInit())
	{
		// Handle initialization failure
	}
	#pragma endregion

	#pragma region createWindow
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	//window = glfwCreateWindow(mode->width, mode->height, "TestWindow", NULL, NULL);
	window = glfwCreateWindow(400, 300, "TestWindow", NULL, NULL);
	if (window == nullptr)//window creation failed
	{
		glfwTerminate();
		printf("Window Creation Failed\n");
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		printf("GLEW failed to initialize.");
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#pragma endregion

	glfwGetCursorPos(window, &GameWindow::mousePos.x, &GameWindow::mousePos.y);
}


GameWindow::~GameWindow()
{
	#pragma region terminate
	glfwTerminate();
	#pragma endregion
}


void GameWindow::setCursorLocked(bool isLocked)
{
	cursorLocked = isLocked;
}


void GameWindow::setCursorVisible(bool visible)
{
	if(!visible)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}


//render clears buffer, updates mouse pos and grabs window related events
void GameWindow::render()
{
	#pragma region mouse
	glm::dvec2 currentMousePos = glm::dvec2(0, 0);
	glfwGetCursorPos(window, &currentMousePos.x, &currentMousePos.y);

	GameWindow::mouseDelta = glm::dvec2(currentMousePos.x - mousePos.x, currentMousePos.y - mousePos.y);
	GameWindow::mousePos = currentMousePos;

	if (cursorLocked)
	{
		int sizeX, sizeY;
		glfwGetWindowSize(window, &sizeX, &sizeY);
		glfwSetCursorPos(window, float(sizeX / 2.f), float(sizeY / 2.f));
	}
	#pragma endregion 

	clock.update();

	//clear buffers & grab window events
	glfwSwapBuffers(window);
	glfwPollEvents();
}


bool GameWindow::isOpen()
{
	return glfwWindowShouldClose(window) == 0;
}


void GameWindow::close()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}


bool GameWindow::keyPressed(int key)
{
	if (window != nullptr)
	{
		//if requested key is mouse button
		if (key >= 0 && key <= 7)
			return glfwGetMouseButton(window, key) == GLFW_PRESS;
		//if requested key is keyboard button
		else
			return glfwGetKey(window, key) == GLFW_PRESS;
	}
	else
		return false;
}


bool GameWindow::keyReleased(int key)
{
	if (window != nullptr)
	{
		//if requested key is mouse button
		if (key >= 0 && key <= 7)
			return glfwGetMouseButton(window, key) == GLFW_RELEASE;
		//if requested key is keyboard button
		else
			return glfwGetKey(window, key) == GLFW_RELEASE;
	}
	else
		return false;
}


bool GameWindow::keyHeld(int key)
{
	if (window != nullptr)
	{
		//if requested key is mouse button
		if (key >= 0 && key <= 7)
			return glfwGetMouseButton(window, key) == GLFW_REPEAT;
		//if requested key is keyboard button
		else
			return glfwGetKey(window, key) == GLFW_REPEAT;
	}
	else
		return false;
}