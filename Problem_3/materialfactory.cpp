#include "materialfactory.hpp"


std::shared_ptr<Material> MaterialFactory::makeGlod()
{
    return std::make_shared<Material>(
                Material{QVector3D(0.24725f, 0.19950f, 0.07450f),
                         QVector3D(0.75164f, 0.60648f, 0.22648f),
                         QVector3D(0.628281f, 0.555802f, 0.366065f),
                         51.2f
                });
}

std::shared_ptr<Material> MaterialFactory::makeCyanPlastic()
{
    return std::make_shared<Material>(
                Material{QVector3D(0.0f       ,  0.1f       ,  0.06f),
                         QVector3D(0.0f       ,  0.50980392f,	0.50980392f),
                         QVector3D(0.50196078f,	0.50196078f,	0.50196078f),
                         32.f
                });
}
