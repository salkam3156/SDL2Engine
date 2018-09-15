#include "Shader.h"

Shader::Shader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
: _ready(false)
{
	_vertexShaderPath = vertexShaderFilePath;
	_fragmentShaderPath = fragmentShaderFilePath;

	try
	{
		if(Load() < 1 || Compile() < 1 || Link() < 1)
		{
			throw ShaderException("Error loading shader file");
		}
		else
		{
			_ready = true;
		}
	}
	catch(ShaderException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

bool Shader::Use()
{
	return true;
}

bool Shader::Ready()
{
	return true;
}

int Shader::Load()
{
	_vertexShaderFile.open(_vertexShaderPath, std::ios::in);
	if(!_vertexShaderFile)
	{
		return -1;
	}

	return 0;
}

int Shader::Compile()
{
	return 0;
}

int Shader::Link()
{
	return 0;
}
