#include "stdafx.h"
#include "GameWindow3D.h"
#include <fstream>
#include <string>
#include <vector>


GameWindow3D::GameWindow3D() : GameWindow()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
}


GameWindow3D::GameWindow3D(const char * vShader, const char * fShader) : GameWindow()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	loadShaders(vShader, fShader);
}


GameWindow3D::~GameWindow3D()
{
	glDeleteProgram(shaderProgram);
}


void GameWindow3D::clear()
{
	GameWindow::clear();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgram);
}


void GameWindow3D::loadShaders(const char * vShader, const char * fShader)
{
	shaderProgram = glCreateProgram();

	std::ifstream vFile(vShader, std::ifstream::in);//vertex shader
	std::ifstream fFile(fShader, std::ifstream::in);//fragment shader

	//if both files open successfully
	if (vFile.is_open() && fFile.is_open())
	{
		std::string vShaderSource = "";
		std::string fShaderSource = "";
		std::string line;

		#pragma region loadShaderData
		//vertex shader data
		while (std::getline(vFile, line))
			vShaderSource += line + "\n";
		const char * vShaderSourcePtr = vShaderSource.c_str();

		//fragment shader data
		while (std::getline(fFile, line))
			fShaderSource += line + "\n";
		const char * fShaderSourcePtr = fShaderSource.c_str();

		//close files
		vFile.close();
		fFile.close();

		#pragma endregion

		GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vShader, 1, &vShaderSourcePtr, NULL);
		glShaderSource(fShader, 1, &fShaderSourcePtr, NULL);
		
		glCompileShader(vShader);
		glCompileShader(fShader);

		//get error messages from shader compilation if any
		int logLen = 0;
		glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logLen);

		//output to console errors if any are there
		if (logLen > 0)
		{
			std::vector<char> log(logLen + 1);
			glGetShaderInfoLog(vShader, logLen, NULL, &log[0]);
			printf("%s\n", &log[0]);
		}
		else
			glAttachShader(shaderProgram, vShader);

		//get error messages from shader compilation if any
		glGetShaderiv(fShader, GL_INFO_LOG_LENGTH, &logLen);

		//output to console errors if any are there
		if (logLen > 0)
		{
			std::vector<char> log(logLen + 1);
			glGetShaderInfoLog(fShader, logLen, NULL, &log[0]);
			printf("%s\n", &log[0]);
		}
		else
			glAttachShader(shaderProgram, fShader);

		glLinkProgram(shaderProgram);

		glDeleteShader(vShader);
		glDeleteShader(fShader);
	}
	else
	{
		printf("Shader files could not be opened. Please check the requested file path.\n");
		return;
	}
}


GLuint GameWindow3D::getProgramID() const
{
	return shaderProgram;
}