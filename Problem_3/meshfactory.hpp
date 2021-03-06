#pragma once
#include "mesh.hpp"

#include <memory>

class MeshFactory
{
public:
    static std::shared_ptr<Mesh> makeCube(QVector3D const& size = {1.f, 1.f, 1.f}, std::size_t grid_steps = 10);

    static std::shared_ptr<Mesh> makeSphere(size_t stackCount,
                                            size_t sectorCount,
                                            float radius = 1.f);
};

