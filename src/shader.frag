#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec2 textCoord;
in vec3 FragPos;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec4 text = mix(texture(texture1, textCoord), 
                    texture(texture2, textCoord), 0.2);

    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    FragColor = vec4(ambient + diffuse, 1.0) * text;
}