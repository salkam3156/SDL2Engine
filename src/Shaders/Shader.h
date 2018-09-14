#pragma once
#include "../StandardHeader.h"

class Shader
{
public:
	Shader(std::string vertexShaderFile, std::string fragmentShaderFile);
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

	bool Ready();
	int Load();
	int Compile();
	int Link();

};
