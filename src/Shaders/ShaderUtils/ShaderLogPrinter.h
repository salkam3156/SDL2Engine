#pragma once
#include "../../StandardHeader.h"

enum class OperationType {
	COMPILE, LINK
};

class ShaderLogPrinter {
public:
	static void PrintLog(GLuint shaderId, OperationType opType) {
		GLint retVal = -1;

		switch (opType) {
		case OperationType::COMPILE:
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &retVal);

			if (retVal != GL_TRUE)
			{
				size_t maxLength = 0;
				glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH,
						reinterpret_cast<GLint*>(&maxLength));
				std::string shaderLog;
				shaderLog.resize(maxLength + 1);
				glGetShaderInfoLog(shaderId, maxLength,
						reinterpret_cast<GLsizei*>(&maxLength), &shaderLog.at(0));
				std::cout << shaderLog << std::endl;
			}

			break;
		case OperationType::LINK:
			glGetProgramiv(shaderId, GL_LINK_STATUS, &retVal);

			if (retVal != GL_TRUE)
			{
				size_t maxLength = 0;
				glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH,
						reinterpret_cast<GLint*>(&maxLength));
				std::string programLog;
				programLog.resize(maxLength + 1);
				glGetProgramInfoLog(shaderId, maxLength,
						reinterpret_cast<GLsizei*>(&maxLength), &programLog.at(0));
				std::cout << programLog << std::endl;
			}
			break;
		}
	}
};
