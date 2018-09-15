#include "StandardHeader.h"
#include "Types/TestState.h"
#include "Instance.h"
#include "Shaders/Shader.h"

//TODO: create logging class
int main(int argc, char* args[])
{
	int retVal = 0;
	Shader shader{"Shaders/ShaderResources/vertex.shader", "Shaders/ShaderResources/fragment.shader"};
	auto instance = Instance::GetInstance();

	while(instance->Running())
	{
		instance->Run();
	}

	return retVal;
}
