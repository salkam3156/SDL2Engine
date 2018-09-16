#version 300 es

in vec2 in_position;
in vec3 in_color;
out vec3 out_color;

void main()
{
	out_color = in_color;
	gl_Position = vec4(in_position, 0.0, 1.0);
}