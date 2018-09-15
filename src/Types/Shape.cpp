#include "Shape.h"

Shape::Shape(ShaderProgram* shader) : DrawableObject()
{
	BindVAO();
	auto vertices = _quad.GetVertices();
	LoadVertices(_quad.GetVertices());
	auto elements = _quad.GetElements();
	LoadElements(_quad.GetElements());
	//_positionAttr = shader->GetAttribute("in_position");
	//_colorAttr = shader->GetAttribute("in_color");

	glEnableVertexAttribArray(shader->_positionAttrLocation);
	//TODO: make stride a member of the struct / implement shape/resource maker
	glVertexAttribPointer(shader->_positionAttrLocation, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(shader->_colorAttribLocation);
	glVertexAttribPointer(shader->_colorAttribLocation, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
}
