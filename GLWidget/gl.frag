#version 330

in lowp vec4 color;
in lowp vec2 textc;
uniform sampler2D texture;

out vec4 FragColor;

void main(void)
{
	//FragColor = color;
	FragColor = texture2D(texture, textc);
}