#version 440 core

in vec3 vert_position;

out vec4 position;

uniform mat4 modelViewProjMat = mat4(1.0f);

void main()
{
	gl_Position = modelViewProjMat * vec4(vert_position, 1.0);
	position = gl_Position;

}