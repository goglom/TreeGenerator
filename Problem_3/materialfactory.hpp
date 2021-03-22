#pragma once

#include "material.hpp"

#include <QString>
#include <map>

class MaterialFactory
{
public:

    inline static Material makeGlod(){
        return Material(
                    QVector3D(0.24725f, 0.19950f, 0.07450f),
                    QVector3D(0.75164f, 0.60648f, 0.22648f),
                    QVector3D(0.628281f, 0.555802f, 0.366065f),
                    51.2f
                    );
    }

    inline static Material makeJade(){
        return Material(
                    QVector3D(0.135,	0.2225,	0.1575),
                    QVector3D(0.54,	0.89,	0.63),
                    QVector3D(0.316228,	0.316228,	0.316228),
                    12.8
                    );
    }

    inline static Material makeCyanPlastic(){
        return Material(
                    Material{QVector3D(0.0f       ,  0.1f       ,  0.06f),
                             QVector3D(0.0f       ,  0.50980392f,	0.50980392f),
                             QVector3D(0.50196078f,	0.50196078f,	0.50196078f),
                             32.f
                    });
    }


    inline static const std::unordered_map<int, Material (*)()> materialMap =
    {{0, &makeGlod}, {1, &makeJade}, {2, &makeCyanPlastic}};

    inline static const std::map<int, QString> names =
    {{0, "Gold"}, {1, "Jade"}, {2, "Cyan Plastic"}};

    inline static Material make(int index){
        return materialMap.at(index)();
    }

};

