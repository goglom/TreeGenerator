#include "texture.hpp"

Texture::Texture(const QImage& image, std::string name)
    : QOpenGLTexture(image),
      shaderName(std::move(name))
{
    textures_.push_back(this);
}

void Texture::uploadToShader(
        QOpenGLFunctions& functions,
        QOpenGLShaderProgram& shader
        )
{
    uint index = std::distance(textures_.begin(), std::find(textures_.begin(), textures_.end(), this));
    shader.setUniformValue(shaderName.c_str(), index);
    functions.glActiveTexture(GL_TEXTURE0 + index);
    bind();
}

Texture::~Texture()
{
    textures_.erase(std::find(textures_.begin(), textures_.end(), this));
}
