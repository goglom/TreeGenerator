#version 450
uniform highp mat4 model;
uniform highp mat3 normModel;
uniform highp mat4 projView;
uniform highp vec3 cameraPos;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct DirLightSource
{
    lowp vec3 color;
    float intensity;
    highp vec3 direction;
};

struct PointLightSource
{
    lowp vec3 color;
    highp vec3 position;
    float intensity;
    float constFactor;
    float linFactor;
    float quadFactor;
};

uniform DirLightSource dirLights[10];
uniform int dirLightsCount;
uniform PointLightSource pointLights[10];
uniform int pointLightsCount;
uniform Material material;

vec3 CalcDirLight(DirLightSource light, vec3 normal, vec3 toEye)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(toEye, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient  = light.color  * material.ambient;
    vec3 diffuse  = light.color * diff * material.diffuse;
    vec3 specular = light.color * spec * material.specular;
    return light.intensity * (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLightSource light, vec3 normal, vec3 vertexPos, vec3 toEye)
{
    vec3 lightDir = normalize(light.position - vertexPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(toEye, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - vertexPos);
    float attenuation = 1.0 / (light.constFactor + light.linFactor * distance +
                             light.quadFactor * distance * distance);
    // combine results
    vec3 ambient  = light.color * material.ambient;
    vec3 diffuse  = light.color * diff * material.diffuse;
    vec3 specular = light.color * spec * material.specular;

    return attenuation * light.intensity * (ambient + diffuse + specular);
}

layout (location = 0) in highp vec3 position;
layout (location = 1) in highp vec3 normal;

out lowp vec4 vertexColor;

void main()
{
    vec3 norm = normModel * normal;
    norm = normalize(norm);
    vec3 toEye = normalize(cameraPos - position);
    vec3 resultCol = vec3(0.0);

    for (int i = 0; i < min(dirLightsCount, 10); ++i)
    {
        resultCol += CalcDirLight(dirLights[i], norm, toEye);
    }
    for (int i = 0; i < min(pointLightsCount, 10); ++i)
    {
        resultCol += CalcPointLight(pointLights[i], norm, position, toEye);
    }

    vertexColor = vec4(resultCol, 1.0);
    gl_Position = projView * model * vec4(position, 1.f);
}
