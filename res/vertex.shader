#version 300 es

in vec2 vert_position;
in vec3 vert_color;

out vec3 vert_out_color;

void main()
{
	vert_out_color = vert_color;
	gl_Position = vec4(vert_position, 0.0, 1.0);
}