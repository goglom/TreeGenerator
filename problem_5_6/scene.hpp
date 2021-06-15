#pragma once

#include "lightsource.hpp"
#include "meshobject.hpp"
#include "direcltylight.hpp"
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <memory>
#include <vector>
#include <set>

class Scene
{
    using LightSourseSPtr = std::shared_ptr<LightSource>;
    using DirectlyLightSourseSPtr = std::shared_ptr<DirecltyLightSource>;
    using RenderObjectSPtr = std::shared_ptr<RenderObject>;
    using ShaderProgramSptr =  std::shared_ptr<QOpenGLShaderProgram>;


    OpenGLFunctionsSPtr pFunctions_;
    ShaderProgramSptr objectShader_;
    ShaderProgramSptr lightSourceShader_;
    QVector3D ambientColor_{};

public:
    std::vector<DirectlyLightSourseSPtr> dirLightSources;
    std::set<RenderObjectSPtr> objects;


    void initialize(
            OpenGLFunctionsSPtr pFunctions,
            ShaderProgramSptr object,
            ShaderProgramSptr lightSrc
            );

    void setAmbientColor(QColor const& color);
    void setAmbientColor(QVector3D const& color);
    QVector3D const& getAmbientColor() const;
    void addDirectlyLightSource(DirectlyLightSourseSPtr light);
    void addRenderObject(RenderObjectSPtr object);

    void renderAll();
    void clean();
};
