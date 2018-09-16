#include "Camera.h"

Camera::Camera(ShaderProgram* shader)
{
	_shader = shader;
	_modelViewProjUniform = _shader->GetUniformMatrixAttrLocation();
	_projectionMatrix = glm::perspective(glm::radians(45.0f), 640/(float)480, 1.0f, 100.0f);

}
void Camera::SetShader(ShaderProgram* shader)
{
	_shader = shader;
	_modelViewProjUniform = _shader->GetUniformMatrixAttrLocation();
}

void Camera::SetTranslation(GLfloat x, GLfloat y, GLfloat z)
{
	_translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));
	UpdateWorldViewMatrix();
}

void Camera::SetRotation(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	_rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(x,y,z));
	UpdateWorldViewMatrix();
}

void Camera::Translate(GLfloat x, GLfloat y, GLfloat z)
{
	_translationMatrix = glm::translate(_translationMatrix, glm::vec3(x,y,z));
	UpdateWorldViewMatrix();
}

void Camera::Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	_rotationMatrix = glm::rotate(_rotationMatrix, glm::radians(angle), glm::vec3(x,y,z));
	UpdateWorldViewMatrix();
}

void Camera::Update()
{
	//TODO: watch out for uniform value
	_shader->SetUniformMatrix(_projectionMatrix * _viewMatrix);//_shader->SetUniformMatrix()
}

void Camera::UpdateWorldViewMatrix()
{
	_viewMatrix = _rotationMatrix * _translationMatrix;
}
