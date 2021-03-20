#pragma once

#include "lightsource.hpp"
#include "meshobject.hpp"
#include "pointlightsource.hpp"
#include "direcltylight.hpp"

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <memory>
#include <vector>

class Scene
{
    using LightSourseSPtr = std::shared_ptr<LightSource>;
    using PointLightSourseSPtr = std::shared_ptr<PointLightSource>;
    using DirectlyLightSourseSPtr = std::shared_ptr<DirecltyLight>;
    using RenderObjectSPtr = std::shared_ptr<RenderObject>;
    using ShaderProgramSptr =  std::shared_ptr<QOpenGLShaderProgram>;

    QOpenGLFunctions& functions_;
    ShaderProgramSptr objectShader_;
    ShaderProgramSptr lightSourceShader_;

public:
    std::vector<PointLightSourseSPtr> pointLightSources;
    std::vector<DirectlyLightSourseSPtr> dirLightSources;    
    std::vector<RenderObjectSPtr> objects;

    Scene(QOpenGLFunctions& fucntions);

    void initialize(ShaderProgramSptr object,
                    ShaderProgramSptr lightSrc
                    );
    void addPointLightSource(PointLightSourseSPtr light);
    void addDirectlyLightSource(DirectlyLightSourseSPtr light);
    void addRenderObject(RenderObjectSPtr object);
    void renderAll();
};
