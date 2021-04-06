#version 450
uniform lowp vec3 lightColor;
uniform sampler2D textureMap;
uniform bool textureMapEnabled;

in vec2 textureCoord;

layout(location = 0) out vec4 fragColor;

void main()
{
    fragColor = vec4(lightColor, 1.0);

    if (textureMapEnabled){
        fragColor *= texture(textureMap, textureCoord);
    }
}
