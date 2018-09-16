#include "Shape.h"

Shape::Shape(ShaderProgram* shader) : DrawableObject()
{
	LoadVertices(_quad.GetVertices());
	LoadElements(_quad.GetElements());

	glEnableVertexAttribArray(shader->_positionAttrLocation);
	//TODO: make stride a member of the struct / implement shape/resource maker
	glVertexAttribPointer(shader->_positionAttrLocation, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(shader->_colorAttribLocation);
	glVertexAttribPointer(shader->_colorAttribLocation, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
}
