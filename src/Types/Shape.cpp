#include "Shape.h"

Shape::Shape(std::shared_ptr<ShaderProgram> shader) : DrawableObject()
{
	LoadVertices(_quad.GetVertices());
	LoadElements(_quad.GetElements());

	glEnableVertexAttribArray(shader->GetPositionAttrLocation());
	//TODO: make stride a member of the struct / implement shape/resource maker
	glVertexAttribPointer(shader->GetPositionAttrLocation(), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(shader->GetColorAttrLocation());
	glVertexAttribPointer(shader->GetColorAttrLocation(), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
}
