#pragma once
#include <QVector3D>
#include <QVector2D>
#include "qopengl.h"

struct Vertex
{
    QVector3D position{};
    inline static constexpr size_t positionTupleSize = sizeof(position) / sizeof(float);
    inline static GLenum positionElemTypeVal = GL_FLOAT;

    QVector3D normal{};
    inline static constexpr size_t normalTupleSize = sizeof(normal) / sizeof(float);
    inline static GLenum normalElemTypeVal = GL_FLOAT;

    QVector2D textCoord{};
    inline static constexpr size_t textCoordTupleSize = sizeof(textCoord) / sizeof(float);
    inline static GLenum textCoordElemTypeVal = GL_FLOAT;

    Vertex() = default;
    Vertex(QVector3D const& pos,
           QVector3D const& norm,
           QVector2D const& texture = {}
           )
        : position(pos),
          normal(norm),
          textCoord(texture)
    {
    }
};

