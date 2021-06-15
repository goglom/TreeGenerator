#pragma once
#include <QVector3D>
#include <memory>
#include <random>
#include <stack>

#include "meshcollectionobject.hpp"
#include "material.hpp"

class TreeBranch;
using TreeBranchUPtr = std::unique_ptr<TreeBranch>;


class TreeBranch
{
public:
    struct Parametrs
    {
        float passRatio = 0.3;
        float splitDecay = 1e-2;
        float feedMin = 1e-5;
        int localDepth = 2;
        float directedness = 0.5;
        float ratio, spread, splitsize;
        float leafSize = 0.5f;
        bool conserveArea = true;
        bool drawLeafs = true;
    };
    class iterator;

    TreeBranch(float ratio, float spread, float splisize);
    TreeBranch(const Parametrs& params);
    bool isLeaf() const;
    void grow(float feed);
    float radius() const;
    float length() const;
    float getEndRadius() const;
    iterator begin();
    iterator end();
    MeshCollectionObjectSPtr GenerateTreeMesh(MaterialSPtr pMaterial);


private:
    TreeBranch(TreeBranch& parent);
    void GenerateBranchMesh(MaterialSPtr pMaterial, std::vector<MeshObjectSPtr>& meshes);
    void split();
    QVector3D leafDensity(int searchDepth);
    QVector3D leafAverage(TreeBranch const& branch);

public:
    Parametrs p;

private:
    TreeBranchUPtr _lChild{};
    TreeBranchUPtr _rChild{};
    TreeBranch * _parent = nullptr;
    QVector3D _direction{0, 1, 0};
    QVector3D _pos{};
    int _depth = 0;
    float _length = 0;
    float _radius = 0;
    float _area = 0.0;
    std::mt19937 _randomGen{};
    std::uniform_real_distribution<float> _onesDistrib{-1.f, 1.f};
};

class TreeBranch::iterator
{
    std::stack<TreeBranch*> _stack = {};
public:

    using reference = TreeBranch&;
    using pointer = TreeBranch*;

    iterator(TreeBranch* root);
    iterator();
    TreeBranch& operator*();
    TreeBranch* operator->();
    iterator& operator++();
    iterator operator++(int);
    bool operator==(iterator const& other);
    bool operator!=(iterator const& other);
};


