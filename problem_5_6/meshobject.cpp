#include "meshobject.hpp"


MeshObject::MeshObject(
        MeshSPtr mesh,
        MaterialSPtr material,
        const QMatrix4x4& modelMatrix
        )
    : pMesh_(std::move(mesh)),
      material_(std::move(material)),
      modelMatrix(modelMatrix)
{
}

MeshObjectSPtr MeshObject::construct(
        MeshSPtr mesh,
        MaterialSPtr material,
        const QMatrix4x4& modelMatrix
        )
{
    return MeshObjectSPtr(
                new MeshObject(std::move(mesh), std::move(material), modelMatrix)
                );
}

RenderObjectSPtr MeshObject::clone() const
{
    return MeshObjectSPtr(new MeshObject(*this));
}

void MeshObject::initialize(OpenGLFunctionsSPtr pFunctions,
                            ShaderProgramSPtr pShaderProgram)
{
    Q_ASSERT(pShaderProgram);
    Q_ASSERT(pFunctions);
    pFunctions_ = std::move(pFunctions);
    pShader_ = std::move(pShaderProgram);

    if (VAO_->isCreated())
        return;

    QOpenGLVertexArrayObject::Binder binder(VAO_.get());
    VBO_.create();
    VBO_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    VBO_.bind();
    VBO_.allocate(pMesh_->vertices.data(),
                  pMesh_->vertices.size() * sizeof(Mesh::vertexType)
                  );

    pShader_->bind();

    // Vertex position
    pShader_->enableAttributeArray(positionLocation);
    pShader_->setAttributeBuffer(
                positionLocation, Mesh::vertexType::positionElemTypeVal,
                offsetof(Mesh::vertexType, position),
                Mesh::vertexType::positionTupleSize, sizeof(Mesh::vertexType)
                );
    // Vertex normal
    pShader_->enableAttributeArray(normalLocation);
    pShader_->setAttributeBuffer(
                normalLocation, Mesh::vertexType::normalElemTypeVal,
                offsetof(Mesh::vertexType, normal),
                Mesh::vertexType::normalTupleSize, sizeof(Mesh::vertexType)
                );
    // Vertex Texture Coordinate
    // If there is no texture in MeshObject initialize don't load texture coordinates
    pShader_->enableAttributeArray(textCoordLocation);
    pShader_->setAttributeBuffer(
                textCoordLocation, Mesh::vertexType::textCoordElemTypeVal,
                offsetof(Mesh::vertexType, textCoord),
                Mesh::vertexType::textCoordTupleSize, sizeof(Mesh::vertexType)
                );

    IBO_.create();
    IBO_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    IBO_.bind();
    IBO_.allocate(pMesh_->indices.data(),
                  pMesh_->indices.size() * sizeof(Mesh::indexType)
                  );
}

void MeshObject::render()
{
    if (modelChanged_){
        normModelMatrix_ = modelMatrix.inverted().transposed();
        modelChanged_ = false;
    }
    shader().bind();
    shader().setUniformValue("model", modelMatrix);
    shader().setUniformValue("normModel", normModelMatrix_);
    shader().setUniformValue("material.ambient",    material_->ambient);
    shader().setUniformValue("material.diffuse",    material_->diffuse);
    shader().setUniformValue("material.specular",   material_->specular);
    shader().setUniformValue("material.shininess",  material_->shininess);

    QOpenGLVertexArrayObject::Binder binder(VAO_.get());
    pFunctions_->glDrawElements(GL_TRIANGLES, pMesh_->indices.size(), Mesh::IndexTypeVal, nullptr);
}

QMatrix4x4& MeshObject::getModel()
{
    modelChanged_ = true;
    return modelMatrix;
}

QMatrix4x4 const& MeshObject::getModel() const
{
    return modelMatrix;
}

void MeshObject::offsetMove(const QVector3D& offset)
{
    getModel().translate(offset);
}

void MeshObject::moveTo(const QVector3D& position)
{
    getModel().setColumn(3, {position, 1.f});
}

void MeshObject::rotate(const QQuaternion& rotation)
{
    QMatrix4x4 rot;
    rot.rotate(rotation);
    getModel().rotate(rotation);// = rot * getModel();
}

QVector3D MeshObject::position() const
{
    return QVector3D{getModel().column(3)};
}

QOpenGLShaderProgram& MeshObject::shader()
{
    Q_ASSERT(pShader_);
    return *pShader_;
}

QOpenGLFunctions& MeshObject::GLFunctions()
{
    Q_ASSERT(pFunctions_);
    return *pFunctions_;
}
