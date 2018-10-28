#pragma once
#include "../StandardHeader.h"
#include "../Shaders/ShaderProgram.h"
#include "DrawableObject.h"
#include "../../res/Quad.h"
#include "../../res/Cube.h"

class Shape : public DrawableObject
{
public:
	Shape(std::shared_ptr<ShaderProgram> shader);
	~Shape() {}


private:
	GLint _positionAttr;
	GLint _colorAttr;
	Quad _quad;
	Cube _cube;

	// Inherited via DrawableObject
	virtual void Move() override;

	// Inherited via DrawableObject
	virtual void Turn() override;
};
