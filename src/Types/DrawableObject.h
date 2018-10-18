#pragma once
#include "../StandardHeader.h"
#include "../Interfaces/IEntity.h"

class DrawableObject: public IEntity {
public:
	DrawableObject();
	bool Draw();
	~DrawableObject();

protected:
	void LoadVertices(std::vector<GLfloat> data);
	void LoadElements(std::vector<GLuint> data);
	void BindVAO();
	void UnbindVAO();

	GLuint _vertexArrayObj;
	GLuint _vertexBufferObj;
	GLuint _elementBufferObj;

	std::vector<GLuint> _elements;
	std::vector<float> _vertices;
};
