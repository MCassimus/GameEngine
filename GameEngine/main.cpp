#include "stdafx.h"
#include "GameWindow.h"
#include "Object.h"
#include "Character.h"


int main()
{
	GameWindow window;
	std::vector<Object *> gameObjects;

	//window.setCursorLocked(true);
	//window.setCursorVisible(false);

	//double startTime = glfwGetTime();
	gameObjects.push_back(new Character("../Models/teapot/teapot.obj"));
	//printf("%f\n", glfwGetTime() - startTime);
	//system("pause");

	do//begin main program loop
	{
		system("cls");

		//window will close when escape key is pressed
		if (window.keyPressed(GameWindow::keyEscape))
			window.close();

		//update every object in game objects vector
		for (size_t i = 0; i < gameObjects.size(); i++)
			gameObjects.at(i)->update();

		//render scene to window
		window.render();
	} while (window.isOpen());

	//system("pause");
	return 0;
}