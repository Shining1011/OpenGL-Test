#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec2 textCoord;
in vec3 FragPos;
in vec3 LightPos;

uniform vec3 lightColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec4 text = mix(texture(texture1, textCoord), 
                    texture(texture2, textCoord), 0.2);

    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    float diffStrength = 0.5;
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diffStrength * diff * lightColor;

    // specular
    float specularStrength = 1.0;
    
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    vec3 specular = specularStrength * spec * lightColor;

    FragColor = vec4(ambient + diffuse + specular, 1.0) * text;
}