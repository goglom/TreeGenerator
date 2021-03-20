#include "pointlightsource.hpp"


PointLightSource::PointLightSource(
        MeshSPtr mesh,
        QMatrix4x4 const& model_matrix,
        QVector3D const& color,
        float intensity,
        float constFactor,
        float linFactor,
        float quadFactor
        )
    : MeshObject(std::move(mesh), model_matrix),
      LightSource(color, intensity),
      position_(model_matrix.column(3)),
      constFactor_(constFactor),
      linFactor_(linFactor),
      quadFactor_(quadFactor)
{
}

void PointLightSource::render(QOpenGLFunctions& functions)
{
    pShaderProgram_->bind();
    pShaderProgram_->setUniformValue("lightColor", color_);

    MeshObject::render(functions);
}

void PointLightSource::uploadToShader(MeshObject::ShaderProgSPtr pShader, size_t index)
{
    pShader->bind();
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].color").c_str(), color_);
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].position").c_str(), position_);
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].intensity").c_str(), intensity_);
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].constFactor").c_str(), constFactor_);
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].linFactor").c_str(), linFactor_);
    pShader->setUniformValue(("pointLights[" + std::to_string(index) + "].quadFactor").c_str(), quadFactor_);
}

void PointLightSource::offsetMove(const QVector3D& offset)
{
    position_ = QVector3D(getModel().column(3));
    MeshObject::offsetMove(offset);
}
