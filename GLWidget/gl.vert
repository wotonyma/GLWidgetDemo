#version 330

layout(location = 0) in highp vec3 aPos;
layout(location = 1) in lowp vec4 aColor;
layout(location = 2) in lowp vec2 aTextc;

out lowp vec4 color;
out lowp vec2 textc;

uniform vec3 factor;

void main(void) 
{
	//vec3 position = aPos * factor;
	//gl_Position = vec4(clamp(position, 0.0, 1.0), 1.0);
	gl_Position = vec4(aPos,1.0);
	color = aColor;
	textc = aTextc;
}

