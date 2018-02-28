#pragma once
#include "GameWindow.h"
class GameWindow3D : public GameWindow
{
public:
	GameWindow3D();
	GameWindow3D(const char *, const char *);//create loading vert and fragment shaders
	~GameWindow3D();
	void clear();
	void loadShaders(const char *, const char *);
	GLuint getProgramID() const;
protected:
	GLuint shaderProgram;
	GLuint vao;
};