#pragma once
#include "../src/StandardHeader.h"
struct Cube
{
	GLfloat _vertexData[24] = {
		// front
		-1.0, -1.0,  1.0,
		 1.0, -1.0,  1.0,
		 1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		 1.0, -1.0, -1.0,
		 1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,
	};

	GLushort _elementsData[36] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3,
	};

	std::vector<GLfloat> GetVertices()
	{
		return std::vector<GLfloat>(_vertexData, _vertexData + sizeof(_vertexData) / sizeof(_vertexData[0]));
	}

	std::vector<GLuint> GetElements()
	{
		return std::vector<GLuint>(_elementsData, _elementsData + sizeof(_elementsData) / sizeof(_elementsData[0]));
	}

};

