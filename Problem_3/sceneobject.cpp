#include "sceneobject.hpp"

SceneObject::SceneObject(RenderObject::MeshSPtr mesh,
                         const QMatrix4x4& model_matrix,
                         MaterialSPrt material
                         )
    : RenderObject(std::move(mesh), model_matrix),
      material_(std::move(material))
{
}

void SceneObject::render(QOpenGLFunctions& functions)
{
    pShaderProgram_->bind();
    pShaderProgram_->setUniformValue("material.ambient",    material_->ambient);
    pShaderProgram_->setUniformValue("material.diffuse",    material_->diffuse);
    pShaderProgram_->setUniformValue("material.specular",   material_->specular);
    pShaderProgram_->setUniformValue("material.shininess",  material_->shininess);

    RenderObject::render(functions);
}

