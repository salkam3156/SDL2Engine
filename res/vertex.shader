#version 300 es

in vec2 in_position;
in vec3 in_color;

out vec3 out_color;

uniform mat4 modelViewProjMat;

void main()
{
	out_color = in_color;
	gl_Position = modelViewProjMat * vec4(in_position, 0.0, 1.0);
}