#pragma once
#include "../StandardHeader.h"
#include "../Shaders/ShaderProgram.h"

class Camera
{
public:
	//TODO: shaderprogram into shared ptr / container
	Camera(ShaderProgram* shader);
	void SetShader(ShaderProgram* shader);

	void SetTranslationVector(float x, float y, float z);
	void SetRotation(float angle, float x, float y, float z);
	void Translate(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Update();

private:
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;

	ShaderProgram* _shader;

	GLint modelViewProjUniform;

	void UpdateWorldViewMatrix();
};
