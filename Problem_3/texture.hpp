#pragma once
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

#include <memory>
#include <atomic>
#include <list>

class Texture : public QOpenGLTexture
{
    inline static std::list<Texture*> textures_;


public:
    std::string shaderName;

    Texture(QImage const& image, std::string name);
    virtual void uploadToShader(
            QOpenGLFunctions& functions,
            QOpenGLShaderProgram& shader
            );
    virtual ~Texture();
};

