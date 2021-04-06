#include "texturedobject.hpp"


TexturedObject::TexturedObject(
        RenderObjectSPtr parent,
        TextureSPtr pTexture
        )
    : RenderObjectDecorator(std::move(parent)),
      pTexture_(std::move(pTexture))
{
}

TexturedObjectSPtr TexturedObject::construct(RenderObjectSPtr parent, TextureSPtr pTexture)
{
    return TexturedObjectSPtr(new TexturedObject(std::move(parent), std::move(pTexture)));
}

void TexturedObject::render()
{
    shader().setUniformValue((pTexture_->shaderName + "Enabled").c_str(), renderTexture);
    pTexture_->uploadToShader(GLFunctions(), shader());

    RenderObjectDecorator::render();
}

RenderObjectSPtr TexturedObject::clone() const
{
    return TexturedObject::construct(
                RenderObjectDecorator::clone(),
                pTexture_
                );
}
