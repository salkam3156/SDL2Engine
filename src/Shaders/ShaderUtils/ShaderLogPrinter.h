#pragma once
#include "../../StandardHeader.h"

class ShaderLogPrinter
{
public:
	static void PrintLog(GLuint shaderId)
	{
		GLint shaderCompiled;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &shaderCompiled);

		if(shaderCompiled == false)
		{
			size_t maxLength;
			glGetShaderiv(shaderId , GL_INFO_LOG_LENGTH, reinterpret_cast<GLint*>(&maxLength));
			std::string vertexCompileLog;
			vertexCompileLog.resize(maxLength + 1);
			glGetShaderInfoLog(shaderId, maxLength, reinterpret_cast<GLsizei*>(&maxLength),&vertexCompileLog.at(0));
			std::cout << vertexCompileLog << std::endl;
		}

	}
};
