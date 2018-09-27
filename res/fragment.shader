#version 330 core

precision lowp float;

in vec3 vert_out_color;

out vec4 outColor;

void main()
{
	outColor = vec4(vert_out_color, 1.0);
}