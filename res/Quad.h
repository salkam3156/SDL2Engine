#pragma once
#include "../src/StandardHeader.h"
struct Quad
{
	std::vector<GLfloat> _vertexData = {
			-0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f
	};

	std::vector <GLuint >_elementsData = {
			0, 1, 2,
			2, 3, 0
	};

	std::vector<GLfloat> GetVertices()
	{
		return _vertexData;
	}

	std::vector<GLuint> GetElements()
	{
		return _elementsData;
	}

};

