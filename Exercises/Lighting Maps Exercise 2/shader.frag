#version 330 core
out vec4 FragColor;

struct Material{
    sampler2D diffuse;
    sampler2D specular;
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

void main()
{
    // ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, textCoord));

    // diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, textCoord));

    // specular
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = spec * light.specular * vec3(texture(material.specular, textCoord));

    FragColor = vec4(ambient + specular, 1.0);
}