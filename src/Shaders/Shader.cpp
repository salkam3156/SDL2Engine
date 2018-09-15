#include "Shader.h"

Shader::Shader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
: _ready(false)
{
	_vertexShaderPath = vertexShaderFilePath;
	_fragmentShaderPath = fragmentShaderFilePath;

	try
	{
		if(Load() != 0 || Compile() != 0 || Link() != 0)
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
	//TODO: file not open exception
	if(!_vertexShaderFile)
	{
		return -1;
	}
	// TODO: refactor , proper error codes and returns
	_vertexShaderStream << _vertexShaderFile.rdbuf();

	_fragmentShaderFile.open(_fragmentShaderPath, std::ios::in);
	if(!_fragmentShaderFile)
	{
		return -1;
	}

	_fragmentShaderStream << _fragmentShaderFile.rdbuf();

	_vertexShaderProgramString = _vertexShaderStream.str();
	_fragmentShaderProgramString = _fragmentShaderStream.str();

	return 0;
}

int Shader::Compile()
{
	//glewExperimental = GLU_TRUE;
	auto glewInitRet = glewInit();
	auto tempVertexSrc = _vertexShaderProgramString.c_str();
	//auto tempFragmentSrc = _fragmentShaderProgramString.c_str();

	_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(_vertexShaderId, 1, &tempVertexSrc, 0);
	GLint compiled;
	glGetShaderiv(_vertexShaderId, GL_COMPILE_STATUS, &compiled);


	return 0;
}

int Shader::Link()
{
	return 0;
}
