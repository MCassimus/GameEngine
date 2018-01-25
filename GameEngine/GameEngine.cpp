#include "stdafx.h"
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <fstream>
#include <vector>
#include <string>

void loadObj(const char *);


int main()
{
	#pragma region initGlfw
	if (!glfwInit())
	{
		// Handle initialization failure
	}
	#pragma endregion
	
	#pragma region oglSetup
	glfwWindowHint(GLFW_SAMPLES, 4);//msaa samples
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//ogl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//ogl 3.3
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	#pragma endregion
	#pragma region createWindow
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWwindow* window = nullptr;
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	window = glfwCreateWindow(mode->width, mode->height, "TestWindow", NULL, NULL);
	if (window == nullptr)//window creation failed
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		return -1;
	}	
	#pragma endregion

	loadObj("../Models/teapot/teapot.obj");

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	#pragma region terminate
	glfwTerminate();
	#pragma endregion
	return 0;
}



typedef struct vec3 {
	GLfloat x, y, z;
	
};
void loadObj(const char * fileName)
{
	std::vector<vec3> vertex, vertexNormal, textureCoordinate;

	std::ifstream iFile(fileName, std::ifstream::in);
	std::string line;

	if (iFile.is_open())
	{
		while (std::getline(iFile, line))
		{
			/*printf(line.substr(0, 2).c_str());*/
			if (line.substr(0, line.find(" ")) == "v")//is vertex
			{
				line = line.substr(line.find(" ") + 2);

				vec3 tempVert;

				tempVert.x = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.y = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.z = std::stof(line);

				vertex.push_back(tempVert);
			}
			else if (line.substr(0, line.find(" ")) == "vn")// is vertex normal
			{
				line = line.substr(line.find(" ") + 1);
				vec3 tempVert;
				tempVert.x = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.y = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.z = std::stof(line);
				vertexNormal.push_back(tempVert);
			}
			else if (line.substr(0, line.find(" ")) == "vt")//is texture coordinate
			{
				line = line.substr(line.find(" ") + 1);
				
				vec3 tempVert;

				tempVert.x = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.y = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.z = std::stof(line);

				textureCoordinate.push_back(tempVert);
			}
			else if (line.substr(0, line.find(" ")) == "f")
			{
				line = line.substr(line.find(" ") + 1);
				printf("%s \n", line.c_str());
			}
		}
	}


	for (int i = 0; i < vertex.size(); i++)
		printf("%i : %f, %f, %f \n", i, vertex.at(i).x, vertex.at(i).y, vertex.at(i).z);
	for (int i = 0; i < vertexNormal.size(); i++)
		printf("%i : %f, %f, %f \n", i, vertexNormal.at(i).x, vertexNormal.at(i).y, vertexNormal.at(i).z);
	for (int i = 0; i < textureCoordinate.size(); i++)
		printf("%i : %f, %f, %f \n", i, textureCoordinate.at(i).x, textureCoordinate.at(i).y, textureCoordinate.at(i).z);
	return;
}