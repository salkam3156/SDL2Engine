#include "Camera.h"

Camera::Camera(std::shared_ptr<ShaderProgram> shader)
{
	_shader = shader;
	_modelViewProjUniform = _shader->GetUniformMatrixAttrLocation();
	_projectionMatrix = glm::perspective(glm::radians(45.0f), 640/(float)480, 1.0f, 2000.0f);

}
void Camera::SetShader(std::shared_ptr<ShaderProgram> shader)
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
	auto modelViewMatrix = _projectionMatrix * _viewMatrix;
	_shader->SetUniformMatrix("modelViewProjMat", modelViewMatrix);//_shader->SetUniformMatrix()
}

void Camera::UpdateWorldViewMatrix()
{
	_viewMatrix = _rotationMatrix * _translationMatrix;
}

void Camera::Move()
{
	auto keyState = SDL_GetKeyboardState(nullptr);
	
	if(keyState[SDL_SCANCODE_UP])
	{
		Translate(0, 0, 0.5);
	}
	else if(keyState[SDL_SCANCODE_DOWN])
	{
		Translate(0, 0, -0.5);
	}
	else if(keyState[SDL_SCANCODE_Q])
	{
		Rotate(-1.5,0, 1, 0);
	}
	else if(keyState[SDL_SCANCODE_W])
	{
		Rotate(1.5,0, 1, 0);
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		Translate(0.25, 0, 0);
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		Translate(-0.25, 0, 0);
	}
}

void Camera::Turn()
{
}
