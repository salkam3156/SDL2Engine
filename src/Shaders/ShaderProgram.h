#pragma once
#include "../StandardHeader.h"
#include "ShaderUtils/ShaderLogPrinter.h"

class ShaderException: public std::runtime_error {
public:
	ShaderException(const std::string& exceptionMsg) :
			std::runtime_error(exceptionMsg) {
	}
};

class ShaderProgram {
public:
	using ShaderProgramPtr = std::unique_ptr<ShaderProgram>;

	ShaderProgram(std::string vertexShaderFilePath,
			std::string fragmentShaderFilePath);
	bool Use();
	GLint GetAttribute(std::string attribName);
	GLint GetUniformLocation(std::string uniformName);
	GLuint _positionAttrLocation, _colorAttribLocation, _uniformLocation;

private:
	bool Ready();
	int Load();
	int Compile();
	int Link();

private:
	std::ifstream _vertexShaderFile, _fragmentShaderFile;

	std::string _vertexShaderPath, _fragmentShaderPath,
			_vertexShaderProgramString, _fragmentShaderProgramString;

	std::stringstream _vertexShaderStream, _fragmentShaderStream;

	GLuint _vertexShaderId, _fragmentShaderId, _compiledProgramId;

	bool _ready;
};
