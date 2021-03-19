#pragma once

#include "renderobject.hpp"
#include "lightsource.hpp"

class PointLightSource : public RenderObject, public LightSource
{
    QVector3D position_;
    float constFactor_;
    float linFactor_;
    float quadFactor_;

public:
    PointLightSource(
            MeshSPtr mesh,
            QMatrix4x4 const& model_matrix,
            QVector3D const& color = {1.f, 1.f, 1.f},
            float intensity = 1.f,
            float constFactor = 1.f,
            float linFactor = 0.7f,
            float quadFactor = 1.8f
            );

    void render(QOpenGLFunctions& functions) override;
    void uploadToShader(ShaderProgSPtr pShader, size_t index) override;
};

