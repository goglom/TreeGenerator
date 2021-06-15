#include "meshcollectionobject.hpp"

MeshCollectionObjectSPtr MeshCollectionObject::construct(
        std::vector<MeshObjectSPtr> meshObjects, QMatrix4x4 const& model)
{
    return MeshCollectionObjectSPtr{new MeshCollectionObject(std::move(meshObjects), model)};
}

QOpenGLShaderProgram& MeshCollectionObject::shader()
{
    return *pShader_;
}

QOpenGLFunctions& MeshCollectionObject::GLFunctions()
{
    return *pFunctions_;
}

void MeshCollectionObject::render()
{
    for (auto& mesh : meshes){
        mesh->render();
    }
}

void MeshCollectionObject::initialize(OpenGLFunctionsSPtr pOpenGLFunctions, ShaderProgramSPtr pShaderProgram)
{
    pFunctions_ = std::move(pOpenGLFunctions);
    pShader_ = std::move(pShaderProgram);

    for (auto& mesh : meshes){
        mesh->modelMatrix = model_ * mesh->modelMatrix;
        mesh->initialize(pFunctions_, pShader_);
    }
}

RenderObjectSPtr MeshCollectionObject::clone() const
{
    throw std::runtime_error("<RenderObjectSPtr Model3DObject::clone() const>: not implemented!");
}

QVector3D MeshCollectionObject::position() const
{
    return QVector3D{model_.column(3)};
}

MeshCollectionObject::MeshCollectionObject(
        std::vector<MeshObjectSPtr> meshObjects, QMatrix4x4 const& model)
    : meshes(std::move(meshObjects)), model_(model)
{

}
