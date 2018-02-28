#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}


Object::Object(const char * file)
{
	loadObj(file);
}


Object::~Object()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);	
}


void Object::loadObj(const char * fileName)
{
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

				glm::vec3 tempVert;

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
				glm::vec3 tempVert;
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

				glm::vec2 tempVert;

				tempVert.x = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.y = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);

				textureCoordinate.push_back(tempVert);
			}
			else if (line.substr(0, line.find(" ")) == "f")//contents of face
			{
				line = line.substr(line.find(" ") + 1);
				//printf("%s \n", line.c_str());
			}
		}
		iFile.close();//completed gathering data from file, can now close.
	}
	else
		printf("File could not be opened. Please check the requested file path.\n");


	/*for (size_t i = 0; i < vertex.size(); i++)
		printf("%i : %f, %f, %f \n", i, vertex.at(i).x, vertex.at(i).y, vertex.at(i).z);
	for (size_t i = 0; i < vertexNormal.size(); i++)
		printf("%i : %f, %f, %f \n", i, vertexNormal.at(i).x, vertexNormal.at(i).y, vertexNormal.at(i).z);
	for (size_t i = 0; i < textureCoordinate.size(); i++)
		printf("%i : %f, %f, %f \n", i, textureCoordinate.at(i).x, textureCoordinate.at(i).y, textureCoordinate.at(i).z);*/

	//give data to buffers
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(glm::vec3), &vertex[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, textureCoordinate.size() * sizeof(glm::vec2), &textureCoordinate[0], GL_STATIC_DRAW);
}


void Object::update()
{
	//printf("updating object\n");
}


void Object::render()
{
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, vertex.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}


glm::vec3 Object::getPosition() const
{
	return position;
}