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
	GLuint GetPositionAttrLocation() const;
	GLuint GetColorAttrLocation() const;
	GLuint GetUniformMatrixAttrLocation() const;
	GLuint GetProgramId() const;
	void SetUniformMatrix(glm::mat4 matrix);

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

	GLuint _positionAttrLocation, _colorAttrLocation, _uniformMatrixLocation;

	bool _ready;
};
