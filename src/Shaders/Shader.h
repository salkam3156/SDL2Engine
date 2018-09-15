#pragma once
#include "../StandardHeader.h"

class ShaderException : public std::runtime_error
{
public:
	ShaderException(const std::string& exceptionMsg) : std::runtime_error(exceptionMsg) {}
};

class Shader
{
public:
	Shader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
	bool Use();

private:
	std::ifstream _vertexShaderFile;
	std::ifstream _fragmentShaderFile;

	std::string _vertexShaderPath;
	std::string _fragmentShaderPath;

	std::stringstream _vertexShaderText;
	std::stringstream _fragmentShaderText;

	std::string _vertexShaderProgram;
	std::string _fragmentShaderProgram;

	GLuint _vertexShaderId;
	GLuint _fragmentShaderId;
	GLuint _compiledProgramId;

	bool _ready;

	bool Ready();
	int Load();
	int Compile();
	int Link();

};
