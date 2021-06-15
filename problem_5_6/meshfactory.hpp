#pragma once
#include "mesh.hpp"
#include "meshcollectionobject.hpp"

#include <memory>


using MeshSPtr = std::shared_ptr<Mesh>;

class MeshFactory
{
public:
    static MeshSPtr makeCube(QVector3D const& size = {1.f, 1.f, 1.f},
                             std::size_t grid_steps = 10);

    static MeshSPtr makeSphere(size_t stackCount, size_t sectorCount,
                                            float radius = 1.f);
    static MeshSPtr makeRectangle(float width, float length);

    static MeshSPtr makeFrustum(float radius1, float radius2, float length,
                                size_t sectorCount = 6);

    static std::vector<MeshSPtr> loadModel3D(std::string const& path);
};

