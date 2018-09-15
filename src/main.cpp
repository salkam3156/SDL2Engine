#include "StandardHeader.h"
#include "Types/TestState.h"
#include "Instance.h"
#include "Shaders/ShaderProgramProgram.h"

//TODO: create logging class
//TODO: resource factory

int main(int argc, char* args[])
{
	int retVal = 0;

	auto instance = Instance::GetInstance();
	ShaderProgram shader = ShaderProgram("res/vertex.shader", "res/fragment.shader");

	while(instance->Running())
	{
		instance->Run();
	}

	return retVal;
}
