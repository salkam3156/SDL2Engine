#pragma once
#include "../StandardHeader.h"
#include "../Shaders/ShaderProgram.h"
#include "DrawableObject.h"
#include "../../res/Quad.h"

class Shape : public DrawableObject
{
public:
	Shape(ShaderProgram* shader);
	~Shape() {}


private:
	GLint _positionAttr;
	GLint _colorAttr;
	Quad _quad;
};
