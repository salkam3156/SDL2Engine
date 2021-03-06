#pragma once
#include "../StandardHeader.h"
#include "../Shaders/ShaderProgram.h"
#include "../Interfaces/IEntity.h"

class Camera : public IEntity
{
public:
	//TODO: shaderprogram into shared ptr / container
	Camera(std::shared_ptr<ShaderProgram> shader);
	void SetShader(std::shared_ptr<ShaderProgram> shader);

	void SetTranslation(GLfloat x, GLfloat y, GLfloat z);
	void SetRotation(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void Translate(GLfloat x, GLfloat y, GLfloat z);
	void Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void Update();

private:
	glm::mat4 _projectionMatrix;
	glm::mat4 _viewMatrix;
	glm::mat4 _translationMatrix;
	glm::mat4 _rotationMatrix;

	std::shared_ptr<ShaderProgram>  _shader;

	GLint _modelViewProjUniform;

	void UpdateWorldViewMatrix();

	// Inherited via IEntity
	virtual void Move() override;

	// Inherited via IEntity
	virtual void Turn() override;
};
