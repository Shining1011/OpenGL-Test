#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextCoord;

out vec2 textCoord;
out vec3 Ambient;
out vec3 Diffuse;
out vec3 Specular;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform vec3 lightColor;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	vec3 normal = mat3(transpose(inverse(view * model))) * aNormal;
	
	vec3 FragPos = vec3(view * model * vec4(aPos, 1.0));
	vec3 LightPos = vec3(view * vec4(lightPos, 1.0));

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
    float specularStrength = 20.0;
    
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    vec3 specular = specularStrength * spec * lightColor;

	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;
	textCoord = aTextCoord;
}