#pragma once
#include "../StandardHeader.h"
#include "../Interfaces/IDrawable.h"

class DrawableObject: public IDrawable {
public:
	DrawableObject();
	bool Draw();
	~DrawableObject();

protected:
	void LoadVertices(std::vector<float> data);
	void LoadElements(std::vector<GLuint> data);
	void BindVAO();
	void UnbindVAO();

private:
	GLuint _vertexArrayObj;
	GLuint _vertexBufferObj;
	GLuint _elementBufferObj;

	std::vector<GLuint> _elements;
	std::vector<float> _vertices;
};
