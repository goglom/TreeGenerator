#include "treebranch.hpp"
#include "meshfactory.hpp"
#include "materialfactory.hpp"
#include <cmath>
#include <QtMath>

namespace {
template<class T>
T mix(T const& x, T const& y, float factor){
    return x * (1.f - factor) + y * factor;
}

}


TreeBranch::TreeBranch(float ratio, float spread, float splitsize)
    : p{.ratio = ratio, .spread = spread, .splitsize = splitsize}
{
}

TreeBranch::TreeBranch(const TreeBranch::Parametrs& params)
    : p(params)
{
}

bool TreeBranch::isLeaf() const
{
    return !_lChild && !_rChild;
}

void TreeBranch::grow(float feed)
{
    if (_parent)
        _pos = _parent->_pos + _parent->_direction * _parent->length();

    _radius = std::sqrt(_area / M_PI);

    if (isLeaf()){
        _length += std::cbrt(feed);
        feed -= std::cbrt(feed) * _area;
        _area += feed / _length;

        if (_length > p.splitsize * std::exp(-p.splitDecay * _depth))
            split();

        return;
    }

    float pass = p.passRatio;

    if (p.conserveArea){
        pass = (_lChild->_area + _rChild->_area) /
                                    (_lChild->_area + _rChild->_area + _area);
    }
    _area += pass * feed / _length;
    feed *= 1.f - pass;

    if (feed < p.feedMin){
        return;
    }
    _lChild->grow(feed * p.ratio);
    _rChild->grow(feed* (1.f - p.ratio));
}

float TreeBranch::radius() const
{
    return _radius;
}

float TreeBranch::length() const
{
    return _length;
}

float TreeBranch::getEndRadius() const
{
    float radius1(0), radius2(0);
    if (_lChild)
        radius1 = _lChild->radius();
    if (_rChild)
        radius2 = _rChild->radius();

    return std::max(radius1, radius2);
}

TreeBranch::iterator TreeBranch::begin()
{
    return iterator(this);
}

TreeBranch::iterator TreeBranch::end()
{
    return iterator();
}

TreeBranch::TreeBranch(TreeBranch& parent)
    : p(parent.p),
      _parent(&parent),
      _depth(parent._depth + 1)
{
}

void TreeBranch::split()
{
    _lChild = TreeBranchUPtr(new TreeBranch(*this));
    _rChild = TreeBranchUPtr(new TreeBranch(*this));


    auto leafDir = leafDensity(p.localDepth);
    auto norm = QVector3D::crossProduct(_direction, leafDir).normalized();

    float flip = std::rand() % 2 ? 1.f : -1.f;

    _lChild->_direction =
            mix(flip * p.spread * norm, _direction, p.ratio).normalized();

    _rChild->_direction =
            mix(flip * p.spread * (-1 * norm), _direction, 1.f - p.ratio).normalized();
}

QVector3D TreeBranch::leafDensity(int searchDepth)
{
    QVector3D randVec{_onesDistrib(_randomGen), _onesDistrib(_randomGen),
                                                    _onesDistrib(_randomGen)};
    if (_depth == 0) {
        return randVec;
    }

    auto const* curBranch = this;
    QVector3D relative;

    while(curBranch->_depth > 0 && searchDepth >= 0) {
        --searchDepth;
        relative += curBranch->_length * curBranch->_direction;
        curBranch = curBranch->_parent;
    }

    return p.directedness * (leafAverage(*curBranch) - relative)
            + (1.f - p.directedness) * randVec;
}

QVector3D TreeBranch::leafAverage(const TreeBranch& branch)
{
    if (branch.isLeaf()){
        return branch._length * branch._direction;
    }
    return branch._length * branch._direction
            + p.ratio * leafAverage(*branch._lChild)
            + (1 - p.ratio) * leafAverage(*branch._rChild);
}

TreeBranch::iterator::iterator(TreeBranch* root)
{
    _stack.push(root);
}

TreeBranch::iterator::iterator()
{
}

TreeBranch& TreeBranch::iterator::operator*()
{
    return *_stack.top();
}

TreeBranch* TreeBranch::iterator::operator->()
{
    return _stack.top();
}

TreeBranch::iterator& TreeBranch::iterator::operator++()
{
    TreeBranch* node = _stack.top();
    _stack.pop();
    if (node->_rChild)
        _stack.push(node->_rChild.get());
    if (node->_lChild)
        _stack.push(node->_lChild.get());

    return *this;
}

bool TreeBranch::iterator::operator==(const TreeBranch::iterator& other)
{
    void* ptr1 = nullptr;
    void* ptr2 = nullptr;
    if (!_stack.empty())
        ptr1 = _stack.top();
    if (!other._stack.empty())
        ptr2 = other._stack.top();

    return ptr1 == ptr2;
}

bool TreeBranch::iterator::operator!=(const TreeBranch::iterator& other)
{
    return !(*this == other);
}

TreeBranch::iterator TreeBranch::iterator::operator++(int)
{
    auto temp = *this;
    ++*this;
    return temp;
}

void TreeBranch::GenerateBranchMesh(MaterialSPtr pMaterial, std::vector<MeshObjectSPtr>& meshes)
{
    auto const& dir = _direction;
    auto rotDir = QVector3D(-dir.z(), 0, dir.x()).normalized();
    float theta = qRadiansToDegrees(std::acos(dir.normalized().y()));
    auto res = MeshObject::construct(MeshFactory::makeFrustum(radius(),
                                    getEndRadius(), length()*1.05), pMaterial);

    auto branchPos = _pos;
    res->offsetMove(branchPos);
    res->rotate(QQuaternion::fromAxisAndAngle(rotDir, -theta));

    meshes.push_back(res);

    if (isLeaf() and p.drawLeafs){
        float radius = _length * p.leafSize;
        auto leaf = MeshObject::construct(MeshFactory::makeSphere(8, 8, radius), std::make_shared<Material>(MaterialFactory::Jade));
        leaf->offsetMove(branchPos + _direction * _length);
        meshes.push_back(leaf);
    }
}

MeshCollectionObjectSPtr TreeBranch::GenerateTreeMesh(MaterialSPtr pMaterial)
{
    std::vector<MeshObjectSPtr> meshes;

    for (auto& branch : *this)
        branch.GenerateBranchMesh(pMaterial, meshes);

    return MeshCollectionObject::construct(std::move(meshes), {});
}
