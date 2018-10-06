#version 440 core

precision highp float;

out vec4 outColor;
in vec4 position;

uniform vec2 light_source;
uniform vec4 uniColor;

void main()
{
	float intensity = 1.0 / length(position / 2 - vec4(light_source.x, -light_source.y, 1.0, 1.0));
	outColor = uniColor * intensity;
}