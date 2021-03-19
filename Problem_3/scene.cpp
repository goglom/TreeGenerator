#include "scene.hpp"

Scene::Scene(QOpenGLFunctions& fucntions)
    : functions_(fucntions)
{
}

void Scene::initialize(Scene::ShaderProgramSptr object, Scene::ShaderProgramSptr lightSrc)
{
    objectShader_ = std::move(object);
    lightSourceShader_ = std::move(lightSrc);

    objectShader_->bind();
    objectShader_->setUniformValue("dirLightsCount", GLint(0));
    objectShader_->setUniformValue("pointLightsCount", GLint(0));

}

void Scene::addPointLightSource(Scene::PointLightSourseSPtr light)
{
    light->initialize(lightSourceShader_);
    objects_.push_back(std::static_pointer_cast<RenderObject>(light));
    pointLightSources_.push_back(std::move(light));

    objectShader_->bind();
    objectShader_->setUniformValue("pointLightsCount", GLint(pointLightSources_.size()));
}

void Scene::addDirectlyLightSource(Scene::DirectlyLightSourseSPtr light)
{
    dirLightSources_.push_back(std::move(light));

    objectShader_->bind();
    objectShader_->setUniformValue("dirLightsCount", GLint(dirLightSources_.size()));
}

void Scene::addRenderObject(Scene::RenderObjectSPtr object)
{
    object->initialize(objectShader_);
    objects_.push_back(std::move(object));
}

void Scene::renderAll()
{
    objectShader_->bind();
    objectShader_->setUniformValue("dirLightsCount", GLint(dirLightSources_.size()));
    objectShader_->setUniformValue("pointLightsCount", GLint(pointLightSources_.size()));


    for (size_t i = 0; i < pointLightSources_.size(); ++i){
        pointLightSources_[i]->uploadToShader(objectShader_, i);
    }
    for (size_t i = 0; i < dirLightSources_.size(); ++i){
        dirLightSources_[i]->uploadToShader(objectShader_, i);
    }
    for (auto& obj : objects_){
        obj->render(functions_);
    }
}
