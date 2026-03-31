#version 330 core
out vec4 FragColor;

struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 normal;
in vec2 textCoord;
in vec3 FragPos;
in vec3 LightPos;

uniform Material material;
uniform Light light;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec4 text = mix(texture(texture1, textCoord), 
                    texture(texture2, textCoord), 0.2);

    // ambient
    vec3 ambient = material.ambient * light.ambient;

    // diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = material.diffuse * diff * light.diffuse;

    // specular
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = material.specular * spec * light.specular;

    FragColor = vec4(ambient + diffuse + specular, 1.0) * text;
}