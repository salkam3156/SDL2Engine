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
//TODO: lua binding or json parsing for settings

int main(int argc, char* args[]) {
	int retVal = 0;

	Json::Reader jsonReader;
	Json::Value obj;

	std::ifstream shadersJson("res/Shaders.json");

	jsonReader.parse(shadersJson, obj);

	std::cout << obj["vertex"].asString() << std::endl;

	auto instance = Instance::GetInstance();
	ShaderProgram shader = ShaderProgram("res/vertex.shader",
			"res/fragment.shader");
	shader.Use();
	Shape shape(&shader);
	Quad quad;

	while (instance->Running()) {
		instance->Run();
		shape.Draw();
	}

	return retVal;
}
