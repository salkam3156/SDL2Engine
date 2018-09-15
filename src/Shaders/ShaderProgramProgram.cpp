#include "ShaderProgramProgram.h"

ShaderProgram::ShaderProgram(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
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

bool ShaderProgram::Use()
{
	if(_ready)
	{
		glUseProgram(_compiledProgramId);
		return true;
	}
	else
	{
		return false;
	}
}

bool ShaderProgram::Ready()
{
	return _ready;
}

int ShaderProgram::Load()
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

int ShaderProgram::Compile()
{
	glewExperimental = GLU_TRUE;
	auto glewInitRet = glewInit();
	auto tempVertexSrc = _vertexShaderProgramString.c_str();
	auto version = glGetString(GL_VERSION);
	//TODO: extract these into a method
	_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(_vertexShaderId, 1, &tempVertexSrc, 0);
	glCompileShader(_vertexShaderId);

	ShaderLogPrinter::PrintLog(_vertexShaderId, OperationType::COMPILE);

	auto tempFragmentSrc = _fragmentShaderProgramString.c_str();

	_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(_fragmentShaderId, 1, &tempFragmentSrc, 0);
	glCompileShader(_fragmentShaderId);

	ShaderLogPrinter::PrintLog(_fragmentShaderId, OperationType::COMPILE);

	return 0;
}

int ShaderProgram::Link()
{
	_compiledProgramId = glCreateProgram();

	glAttachShader(_compiledProgramId, _vertexShaderId);
	glAttachShader(_compiledProgramId, _fragmentShaderId);

	glLinkProgram(_compiledProgramId);

	ShaderLogPrinter::PrintLog(_compiledProgramId, OperationType::LINK);

	return 0;
}
