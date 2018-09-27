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


	static std::shared_ptr<ShaderProgram> MakeShaderProgram(std::string vertexShaderFilePath,
			std::string fragmentShaderFilePath)
	{
		return std::make_shared<ShaderProgram>(vertexShaderFilePath, fragmentShaderFilePath);
	}

	ShaderProgram(std::string vertexShaderFilePath,
					std::string fragmentShaderFilePath);
	bool Use();
	void Disable();
	GLint GetAttribute(std::string attribName);
	GLuint GetPositionAttrLocation() const;
	GLuint GetColorAttrLocation() const;
	GLuint GetUniformMatrixAttrLocation() const;
	GLuint GetProgramId() const;
	void SetUniformMatrix(std::string name, glm::mat4 matrix);
	~ShaderProgram();

private:
	bool Ready();
	int Load(std::string vertPath , std::string fragPath);
	int Compile();
	int Link();
	GLint GetUniformLocation(std::string uniformName);

private:
	std::string _vertexShaderProgramString, _fragmentShaderProgramString;

	GLuint _vertexShaderId, _fragmentShaderId, _compiledProgramId;

	GLuint _positionAttrLocation, _colorAttrLocation, _uniformMatrixLocation;

	bool _ready;
};
