#include "StandardHeader.h"
#include "Types/TestState.h"
#include "Instance.h"
#include "Shaders/ShaderProgram.h"
#include "Types/Shape.h"
#include "../res/Quad.h"

//TODO: create overall logging and exception classes , and do logging on exception ctor invocation
//TODO: wrap stuff into unique ptrs
//TODO: resource factory
//TODO: platform checker, and dynamically assigning shader versions (modify #version ?) in the shader files / shader generator
//TODO: model loader
//TODO: input handler

int main(int argc, char* args[]) {
	int retVal = 0;

	auto instance = Instance::GetInstance();
	ShaderProgram shaderProgram = ShaderProgram("res/vertex.shader", "res/fragment.shader");
	shaderProgram.Use();
	Shape shape(&shaderProgram);

	while (instance->Running()) {
		instance->Update();
		shape.Draw();
	}

	return retVal;
}
