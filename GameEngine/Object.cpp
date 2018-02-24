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

				glm::vec3 tempVert;

				tempVert.x = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.y = std::stof(line.substr(0, line.find(" ")));
				line = line.substr(line.find(" ") + 1);
				tempVert.z = std::stof(line);

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
}


void Object::update()
{
	//printf("updating object\n");
}


glm::vec3 Object::getPosition() const
{
	return position;
}