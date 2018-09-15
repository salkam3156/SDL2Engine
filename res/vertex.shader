#version 300 es

in vec2 position;
in vec3 color;

out vec3 outColor;

void main()
{
	outColor = color;
	gl_Position = vec4(position, 0.0, 1.0);
}