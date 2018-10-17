#include "DrawableObject.h"

DrawableObject::DrawableObject() :
		_vertexArrayObj(0), _vertexBufferObj(0), _elementBufferObj(
				0) {

	glGenVertexArrays(1, &_vertexArrayObj);
	BindVAO();
}

bool DrawableObject::Draw() {
	bool retVal = false;

	if (_vertexArrayObj == 0 || _vertexBufferObj == 0) {

	} else {
		glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
		retVal = true;
	}

	return retVal;
}

DrawableObject::~DrawableObject() {
	UnbindVAO();

	if (_elementBufferObj) {
		glDeleteBuffers(1, &_elementBufferObj);
	}
	if (_vertexBufferObj) {
		glDeleteBuffers(1, &_vertexBufferObj);
	}
	if (_vertexArrayObj) {
		glDeleteVertexArrays(1, &_vertexArrayObj);
	}

}

void DrawableObject::LoadVertices(std::vector<GLfloat> data) {

	//TODO: watch for performance
	_vertices = data;

	glGenBuffers(1, &_vertexBufferObj);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObj);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _vertices.size(),
			_vertices.data(), GL_STATIC_DRAW);
}

void DrawableObject::LoadElements(std::vector<GLuint> data) {
	_elements = data;

	glGenBuffers(1, &_elementBufferObj);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObj);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _elements.size(),
			_elements.data(), GL_STATIC_DRAW);
}

void DrawableObject::BindVAO() {
	glBindVertexArray(_vertexArrayObj);
}

void DrawableObject::UnbindVAO() {
	glBindVertexArray(0);
}
