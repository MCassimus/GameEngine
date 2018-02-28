#pragma once
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>
#include <fstream>


class Object
{
public:
	Object();
	Object(const char *);
	~Object();
	void loadObj(const char *);
	virtual void update();
	virtual void render();
	glm::vec3 getPosition() const;
protected:
	std::vector<glm::vec3> vertex;
	std::vector<glm::vec3> vertexNormal;
	std::vector<glm::vec2> textureCoordinate;
	glm::vec3 position;

	GLuint vertexbuffer;
	GLuint uvbuffer;
};