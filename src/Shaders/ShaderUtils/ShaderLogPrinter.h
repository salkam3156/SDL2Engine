#pragma once
#include "../../StandardHeader.h"

enum class OperationType
{
	COMPILE,
	LINK
};

class ShaderLogPrinter
{
public:
	static void PrintLog(GLuint shaderId, OperationType opType)
	{
		GLint success;

		switch(opType)
		{
		case OperationType::COMPILE:
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
			break;
		case OperationType::LINK:
			glGetShaderiv(shaderId, GL_LINK_STATUS, &success);
			break;
		}

		if(success == false)
		{
			size_t maxLength;
			glGetShaderiv(shaderId , GL_INFO_LOG_LENGTH, reinterpret_cast<GLint*>(&maxLength));
			std::string shaderLog;
			shaderLog.resize(maxLength + 1);
			glGetShaderInfoLog(shaderId, maxLength, reinterpret_cast<GLsizei*>(&maxLength),&shaderLog.at(0));
			std::cout << shaderLog << std::endl;
		}

	}
};
