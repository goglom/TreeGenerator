#pragma once

#include "material.hpp"

#include <memory>

class MaterialFactory
{
public:

    static std::shared_ptr<Material> makeGlod();
     static std::shared_ptr<Material> makeCyanPlastic();
};

