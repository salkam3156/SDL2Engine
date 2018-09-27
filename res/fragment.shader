#version 330 core

precision lowp float;

in vec3 vert_out_color;

out vec4 outColor;

uniform vec3 light_source = vec3(1.0f);

void main()
{
	outColor = vec4(light_source, 1.0);
}