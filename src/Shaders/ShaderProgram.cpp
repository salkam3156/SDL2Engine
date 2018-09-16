#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexShaderFilePath,
		std::string fragmentShaderFilePath) :
		_ready(false) {
	_vertexShaderPath = vertexShaderFilePath;
	_fragmentShaderPath = fragmentShaderFilePath;

	try {
		if (Load() != 0 || Compile() != 0 || Link() != 0) {
			throw ShaderException("Error loading shader file");
		} else {
			_ready = true;
		}
	} catch (ShaderException& ex) {
		std::cout << ex.what() << std::endl;
	}
}

bool ShaderProgram::Use() {
	if (_ready) {
		glUseProgram(_compiledProgramId);
	}
	return _ready;

}

GLuint ShaderProgram::GetProgramId() const
{
	return _compiledProgramId;
}

GLuint ShaderProgram::GetPositionAttrLocation() const
{
	return _positionAttrLocation;
}

GLuint ShaderProgram::GetColorAttrLocation() const
{
	return _colorAttrLocation;
}

GLuint ShaderProgram::GetUniformMatrixAttrLocation() const
{
	return _uniformMatrixLocation;
}

GLint ShaderProgram::GetAttribute(std::string attribName) {
	return glGetAttribLocation(_compiledProgramId, attribName.c_str());
}

bool ShaderProgram::Ready() {
	return _ready;
}

int ShaderProgram::Load() {
	_vertexShaderFile.open(_vertexShaderPath, std::ios::in);
	//TODO: file not open exception
	if (!_vertexShaderFile) {
		return -1;
	}
	// TODO: refactor , proper error codes and returns
	_vertexShaderStream << _vertexShaderFile.rdbuf();

	_fragmentShaderFile.open(_fragmentShaderPath, std::ios::in);
	if (!_fragmentShaderFile) {
		return -1;
	}

	_fragmentShaderStream << _fragmentShaderFile.rdbuf();

	_vertexShaderProgramString = _vertexShaderStream.str();
	_fragmentShaderProgramString = _fragmentShaderStream.str();

	return 0;
}

int ShaderProgram::Compile() {

	auto tempVertexSrc = _vertexShaderProgramString.c_str();
	//TODO: extract these into a method
	_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShaderId, 1, &tempVertexSrc, 0);
	glCompileShader(_vertexShaderId);

	ShaderLogPrinter::PrintLog(_vertexShaderId, OperationType::COMPILE);

	auto tempFragmentSrc = _fragmentShaderProgramString.c_str();
	_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragmentShaderId, 1, &tempFragmentSrc, 0);
	glCompileShader(_fragmentShaderId);

	ShaderLogPrinter::PrintLog(_fragmentShaderId, OperationType::COMPILE);

	return 0;
}

void ShaderProgram::SetUniformMatrix(glm::mat4 matrix)
{
//	glBindAttribLocation(_compiledProgramId, 1, "modelViewProjMat");
//	_uniformMatrixLocation = 1;

	glUniformMatrix4fv(_uniformMatrixLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

int ShaderProgram::Link() {
	_compiledProgramId = glCreateProgram();

	glAttachShader(_compiledProgramId, _vertexShaderId);
	glAttachShader(_compiledProgramId, _fragmentShaderId);

	glBindAttribLocation(_compiledProgramId, 1, "vert_position");
	_positionAttrLocation = 1;

	glBindAttribLocation(_compiledProgramId, 2, "vert_color");
	_colorAttrLocation = 2;

	glLinkProgram(_compiledProgramId);

	_uniformMatrixLocation = glGetUniformLocation(_compiledProgramId,"modelViewProjMat");

	if(_uniformMatrixLocation < 0)
	{
		throw;
	}

	ShaderLogPrinter::PrintLog(_compiledProgramId, OperationType::LINK);

	return 0;
}
