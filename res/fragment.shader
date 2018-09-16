#version 300 es

precision mediump float;

in vec3 out_color;

out vec4 outColor;

void main()
{
	outColor = vec4(out_color, 1.0);
}