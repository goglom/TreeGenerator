#pragma once

#include <QVector3D>

class Object
{   
public:
    virtual void offsetMove(QVector3D const& offset) = 0;
    virtual void moveTo(QVector3D const& position) = 0;

};
