#pragma once
#include "mesh.hpp"

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

#include <memory>

class RenderObject
{
    using VaoSPtr = std::shared_ptr<QOpenGLVertexArrayObject>;

    std::shared_ptr<Mesh> pMesh_;
    VaoSPtr VAO_ = std::make_shared<QOpenGLVertexArrayObject>();
    QOpenGLBuffer VBO_{QOpenGLBuffer::VertexBuffer};
    QOpenGLBuffer IBO_{QOpenGLBuffer::IndexBuffer};

    QMatrix4x4 modelMatrix_;
    QMatrix3x3 normModelMatrix_;
    bool modelChanged_ = false;
    inline static constexpr int positionLocation = 0;
    inline static constexpr int normalLocation = 1;

protected:
    std::shared_ptr<QOpenGLShaderProgram> pShaderProgram_;

public:
    using ShaderProgSPtr = std::shared_ptr<QOpenGLShaderProgram>;
    using MeshSPtr = std::shared_ptr<Mesh>;

    RenderObject(MeshSPtr mesh,
                 QMatrix4x4 const& model_matrix
                 );
    RenderObject(RenderObject const& other) = default;

    virtual void initialize(ShaderProgSPtr pShaderProgram);
    virtual void render(QOpenGLFunctions& functions);

    QMatrix4x4& getModel();
    QMatrix4x4 const& getModel() const;
};

