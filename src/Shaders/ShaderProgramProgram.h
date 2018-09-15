#pragma once
#include "../StandardHeader.h"
#include "ShaderUtils/ShaderLogPrinter.h"

class ShaderException : public std::runtime_error
{
public:
	ShaderException(const std::string& exceptionMsg) : std::runtime_error(exceptionMsg) {}
};

class ShaderProgram
{
public:
	ShaderProgram(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
	bool Use();

private:
	bool Ready();
	int Load();
	int Compile();
	int Link();

private:
	std::ifstream _vertexShaderFile;
	std::ifstream _fragmentShaderFile;

	std::string _vertexShaderPath;
	std::string _fragmentShaderPath;

	std::stringstream _vertexShaderStream;
	std::stringstream _fragmentShaderStream;

	std::string _vertexShaderProgramString;
	std::string _fragmentShaderProgramString;

	GLuint _vertexShaderId;
	GLuint _fragmentShaderId;
	GLuint _compiledProgramId;

	bool _ready;
};
