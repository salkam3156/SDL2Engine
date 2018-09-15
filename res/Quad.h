#pragma once
#include "../src/StandardHeader.h"
struct Quad
{
	GLfloat _vertexData[20] = {
			-0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f
	};

	GLuint _elementsData[6] = {
			0, 1, 2,
			2, 3, 0
	};

	std::vector<GLfloat> GetVertices()
	{
		return std::vector<GLfloat>(_vertexData, _vertexData + sizeof(_vertexData)/sizeof(_vertexData[0]));
	}

	std::vector<GLuint> GetElements()
	{
		return std::vector<GLuint>(_elementsData, _elementsData + sizeof(_elementsData)/sizeof(_elementsData[0]));
	}

};

