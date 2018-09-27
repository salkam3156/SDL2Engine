#version 330 core

in vec2 vert_position;
in vec3 vert_color;

out vec3 vert_out_color;

uniform mat4 modelViewProjMat = mat4(1.0f);

void main()
{
	vert_out_color = vert_color;
	gl_Position = modelViewProjMat * vec4(vert_position, 0.0, 1.0);
}