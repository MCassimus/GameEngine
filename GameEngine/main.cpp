#include "stdafx.h"
#include "GameWindow3D.h"
#include "Character.h"
#include "Object.h"


int main()
{
	GameWindow3D window("../Shaders/vertexShader.glsl", "../Shaders/fragmentShader.glsl");
	std::vector<Object *> gameObjects;

	//dont do this?
	//window.setCursorLocked(true);
	//window.setCursorVisible(true);

	gameObjects.push_back(new Character());
	gameObjects.push_back(new Object("../Models/teapot/teapot.obj"));
	
	do//begin main program loop
	{
		window.clear();
		
		system("cls");//**Debug** clear any data writtent to console 
		
		#pragma region eventHandling
		//window will close when escape key is pressed
		if (window.keyPressed(GameWindow::keyEscape))
			window.close();
		#pragma endregion

		for (size_t i = 0; i < gameObjects.size(); i++)//update every object in game objects vector
			gameObjects.at(i)->update();

		for (size_t i = 0; i < gameObjects.size(); i++)//render every object in game objects vector
			gameObjects.at(i)->render();

		window.render();
	} while (window.isOpen());

	return 0;
}