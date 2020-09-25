#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture_normal1;
uniform sampler2D texture_normal2;

uniform float mixValue;

void main()
{
    //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	//FragColor = texture(texture_normal1, TexCoord);
	FragColor = mix(texture(texture_normal1, TexCoord), texture(texture_normal2, TexCoord), mixValue);
} 