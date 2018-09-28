#version 330 core

precision highp float;

out vec4 outColor;
in vec4 position;

uniform vec2 light_source;
uniform vec4 uniColor;

void main()
{
	float intensity = .7 / length(position - vec4(light_source.xy, 1.0, 1.0));
	outColor = uniColor * intensity;
}