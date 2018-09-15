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

bool Shader::Ready()
{
	return _ready;
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



	glewExperimental = GLU_TRUE;
	auto glewInitRet = glewInit();
	auto tempVertexSrc = _vertexShaderProgramString.c_str();
	auto version = glGetString(GL_VERSION);
	//TODO: extract these into a method
	_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(_vertexShaderId, 1, &tempVertexSrc, 0);
	GLint vertexCompiled;
	glCompileShader(_vertexShaderId);
	glGetShaderiv(_vertexShaderId, GL_COMPILE_STATUS, &vertexCompiled);

	if(vertexCompiled == false)
	{
		size_t maxLength;
		glGetShaderiv(_vertexShaderId , GL_INFO_LOG_LENGTH, reinterpret_cast<GLint*>(&maxLength));
		std::string vertexCompileLog;
		vertexCompileLog.resize(maxLength + 1);
		glGetShaderInfoLog(_vertexShaderId, maxLength, reinterpret_cast<GLsizei*>(&maxLength),&vertexCompileLog.at(0));
		std::cout << vertexCompileLog << std::endl;
		return -1;
	}

	auto tempFragmentSrc = _fragmentShaderProgramString.c_str();

	_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(_fragmentShaderId, 1, &tempFragmentSrc, 0);
	GLint fragmentCompiled;
	glCompileShader(_fragmentShaderId);
	glGetShaderiv(_fragmentShaderId, GL_COMPILE_STATUS, &fragmentCompiled);

	if(fragmentCompiled == false)
	{
		size_t maxLength;
		glGetShaderiv(_fragmentShaderId , GL_INFO_LOG_LENGTH, reinterpret_cast<GLint*>(&maxLength));
		std::string fragmentCompileLog;
		fragmentCompileLog.resize(maxLength + 1);
		glGetShaderInfoLog(_fragmentShaderId, maxLength, reinterpret_cast<GLsizei*>(&maxLength),&fragmentCompileLog.at(0));
		std::cout << fragmentCompileLog << std::endl;
		return -1;
	}

	return 0;
}

int Shader::Link()
{
	_compiledProgramId = glCreateProgram();

	glAttachShader(_compiledProgramId, _vertexShaderId);
	glAttachShader(_compiledProgramId, _fragmentShaderId);

	glLinkProgram(_compiledProgramId);

	GLint linked;
	glGetProgramiv(_compiledProgramId, GL_LINK_STATUS, &linked);
	if(linked != 0)
	{
		size_t maxLength;
		glGetProgramiv(_compiledProgramId , GL_INFO_LOG_LENGTH, reinterpret_cast<GLint*>(&maxLength));
		std::string programLinkedLog;
		programLinkedLog.resize(maxLength + 1);
		glGetProgramInfoLog(_compiledProgramId, maxLength, reinterpret_cast<GLsizei*>(&maxLength),&programLinkedLog.at(0));
		return -1;
	}


	return 0;
}
