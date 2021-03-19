#pragma once
#include <memory>
#include <QOpenGLShaderProgram>

class LightSource
{
protected:
    QVector3D color_{1.f, 1.f, 1.f};
    float intensity_ = 1.f;

public:

    LightSource(QVector3D const& color,
                float intensity
                )
        : color_(color), intensity_(intensity)
    {
    }

    virtual void uploadToShader(
            std::shared_ptr<QOpenGLShaderProgram> shader,
            size_t index) = 0;
};

