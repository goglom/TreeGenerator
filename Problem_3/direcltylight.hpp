#pragma once

#include "lightsource.hpp"

class DirecltyLight : protected LightSource
{
    QVector3D direction_;

public:
    DirecltyLight(QVector3D const& color,
                  float intensity,
                  QVector3D const& direction
                  );
    void uploadToShader(std::shared_ptr<QOpenGLShaderProgram> shader,
                                size_t index) override;
};

