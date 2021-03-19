#pragma once

#include <QVector3D>

struct Material
{
    QVector3D ambient;
    QVector3D diffuse;
    QVector3D specular;
    float shininess;
};
