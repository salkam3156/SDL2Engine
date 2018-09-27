#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexShaderFilePath, std::string fragmentShaderFilePath) :
		_ready(false)
{

	try {
		if (Load(vertexShaderFilePath, fragmentShaderFilePath) != 0 || Compile() != 0 || Link() != 0) {
			throw ShaderException("Error loading shader file");
		} else {
			_ready = true;
		}
	} catch (ShaderException& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void ShaderProgram::Disable()
{
	glUseProgram(0);
}

GLint ShaderProgram::GetUniformLocation(std::string uniformName)
{
	return glGetUniformLocation(_compiledProgramId ,uniformName.c_str());
}

ShaderProgram::~ShaderProgram()
{
	Disable();
	glDeleteShader(_vertexShaderId);
	glDeleteShader(_fragmentShaderId);
	glDeleteProgram(_compiledProgramId);
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

int ShaderProgram::Load(std::string vertPath , std::string fragPath) {

	std::ifstream vertexShaderFile;
	vertexShaderFile.open(vertPath, std::ios::in);
	//TODO: file not open exception
	if (!vertexShaderFile) {
		return -1;
	}

	// TODO: refactor , proper error codes and returns
	std::stringstream vertexShaderStream;
	vertexShaderStream << vertexShaderFile.rdbuf();

	std::ifstream fragmentShaderFile;
	fragmentShaderFile.open(fragPath, std::ios::in);
	if (!fragmentShaderFile) {
		return -1;
	}

	std::stringstream fragmentShaderStream;
	fragmentShaderStream << fragmentShaderFile.rdbuf();

	_vertexShaderProgramString = vertexShaderStream.str();
	_fragmentShaderProgramString = fragmentShaderStream.str();

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

void ShaderProgram::SetUniformMatrix(std::string name, glm::mat4 matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
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
	glValidateProgram(_compiledProgramId);

	_uniformMatrixLocation = glGetUniformLocation(_compiledProgramId,"modelViewProjMat");

	if(_uniformMatrixLocation < 0)
	{
		throw;
	}

	ShaderLogPrinter::PrintLog(_compiledProgramId, OperationType::LINK);

	return 0;
}
