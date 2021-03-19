#include "renderobject.hpp"



RenderObject::RenderObject(
        std::shared_ptr<Mesh> mesh,
        QMatrix4x4 const& model_matrix
        )
    : pMesh_(std::move(mesh)),
      modelMatrix_(model_matrix)
{
}


void RenderObject::initialize(ShaderProgSPtr pShaderProgram)
{
    Q_ASSERT(pShaderProgram);
    pShaderProgram_ = std::move(pShaderProgram);

    if (VAO_->isCreated())
        return;

    QOpenGLVertexArrayObject::Binder binder(VAO_.get());

    VBO_.create();
    VBO_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    VBO_.bind();
    VBO_.allocate(pMesh_->vertices.data(),
                  pMesh_->vertices.size() * sizeof(Mesh::vertexType)
                  );

    pShaderProgram_->bind();
    pShaderProgram_->enableAttributeArray(positionLocation);
    // Vertex position
    pShaderProgram_->setAttributeBuffer(
                positionLocation, GL_FLOAT, offsetof(Mesh::vertexType, position),
                Mesh::vertexType::positionTupleSize, sizeof(Mesh::vertexType)
                );
    // Vertex normal
    pShaderProgram_->enableAttributeArray(normalLocation);
    pShaderProgram_->setAttributeBuffer(
                normalLocation, GL_FLOAT, offsetof(Mesh::vertexType, normal),
                Mesh::vertexType::normalTupleSize, sizeof(Mesh::vertexType)
                );

    IBO_.create();
    IBO_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    IBO_.bind();
    IBO_.allocate(pMesh_->indices.data(),
                  pMesh_->indices.size() * sizeof(Mesh::indexType)
                  );
}

void RenderObject::render(QOpenGLFunctions& functions)
{
    Q_ASSERT(pShaderProgram_);

    if (modelChanged_){
        normModelMatrix_ = modelMatrix_.inverted().transposed().toGenericMatrix<3, 3>();
        modelChanged_ = false;
    }

    QOpenGLVertexArrayObject::Binder binder(VAO_.get());
    pShaderProgram_->bind();
    pShaderProgram_->setUniformValue("model", modelMatrix_);
    pShaderProgram_->setUniformValue("normModel", normModelMatrix_);

    functions.glDrawElements(GL_TRIANGLES, pMesh_->indices.size(), Mesh::IndexTypeVal, nullptr);
}

QMatrix4x4& RenderObject::getModel()
{
    modelChanged_ = true;
    return modelMatrix_;
}

QMatrix4x4 const& RenderObject::getModel() const
{
    return modelMatrix_;
}
