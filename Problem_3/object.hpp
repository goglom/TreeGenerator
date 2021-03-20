#pragma once

#include <QVector3D>

class Object
{   
public:
    virtual void offsetMove(QVector3D const&){};
    virtual void moveTo(QVector3D const&){};
};
