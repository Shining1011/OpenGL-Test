#version 330 core

in vec3 ourColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform float mixFactor;

void main()
{
    FragColor = mix(texture(texture_1, TexCoord),texture(texture_2, TexCoord), mixFactor);
}