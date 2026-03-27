#version 330 core
out vec4 FragColor;

in vec2 textCoord;

in vec3 Ambient;
in vec3 Diffuse;
in vec3 Specular;


uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec4 text = mix(texture(texture1, textCoord), 
                    texture(texture2, textCoord), 0.2);

    FragColor = vec4(Ambient + Diffuse + Specular, 1.0) * text;
}