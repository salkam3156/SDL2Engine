#include "Shape.h"

Shape::Shape(std::shared_ptr<ShaderProgram> shader) : DrawableObject()
{
	LoadVertices(_cube.GetVertices());
	//LoadElements(_cube.GetElements());

	glEnableVertexAttribArray(shader->GetPositionAttrLocation());
	//TODO: make stride a member of the struct / implement shape/resource maker
	glVertexAttribPointer(shader->GetPositionAttrLocation(), 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(shader->GetColorAttrLocation());
	glVertexAttribPointer(shader->GetColorAttrLocation(), 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
}

void Shape::Move()
{
}

void Shape::Turn()
{
}
