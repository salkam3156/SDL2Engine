#include "DrawableObject.h"

DrawableObject::DrawableObject() :
		_vertexArrayObj(GLuint { 0 }), _vertexBufferObj(GLuint { 0 }), _elementBufferObj(
				GLuint { 0 }) {

	glGenVertexArrays(1, &_vertexArrayObj);
}

bool DrawableObject::Draw() {
	bool retVal = false;

	if(_vertexArrayObj == 0 || _vertexBufferObj == 0 || _elementBufferObj == 0)
	{

	}
	else
	{
		BindVAO();
		glDrawElements(GL_TRIANGLES, _elements.size(), GL_UNSIGNED_INT, 0);
		retVal = true;
	}

	return retVal;
}

DrawableObject::~DrawableObject() {

}

void DrawableObject::LoadVertices(std::vector<float> data) {
	
	//TODO: watch for performance
	_vertices = data;

	glGenBuffers(1, &_vertexBufferObj);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObj);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);
}

void DrawableObject::LoadElements(std::vector<GLuint> data) {
	_elements = data;

	glGenBuffers(1, &_elementBufferObj);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObj);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _elements.size(), _elements.data(), GL_STATIC_DRAW);
}

void DrawableObject::BindVAO() {
	glBindVertexArray(_vertexArrayObj);
}

void DrawableObject::UnbindVAO() {
	glBindVertexArray(0);
}
