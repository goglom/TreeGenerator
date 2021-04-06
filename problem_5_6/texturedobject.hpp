#pragma once

#include "renderobjectdecorator.hpp"
#include "texture.hpp"

#include <QOpenGLTexture>

class TexturedObject;
using TexturedObjectSPtr = std::shared_ptr<TexturedObject>;

using TextureSPtr = std::shared_ptr<Texture>;

class TexturedObject : public RenderObjectDecorator
{
    TextureSPtr pTexture_;

private:
    friend TextureSPtr;

    TexturedObject(
            RenderObjectSPtr parent,
            TextureSPtr pTexture
            );
public:

    static TexturedObjectSPtr construct(RenderObjectSPtr parent, TextureSPtr pTexture);

    bool renderTexture = true;
    void render() override;
    RenderObjectSPtr clone() const override;
    bool drawTexture = true;

};

