/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "scenewidget.hpp"

#include <QMouseEvent>
#include <iostream>
#include <cmath>

namespace{

QVector3D getGlColor(QColor const& color){
    QVector3D result;
    result.setX(color.redF());
    result.setY(color.greenF());
    result.setZ(color.blueF());

    return result;
}

}


SceneWidget::SceneWidget(QWidget* parent)
     : QOpenGLWidget(parent),
       scene(*this),
       keyStates(maxKeyCode, false)
{
}

SceneWidget::~SceneWidget()
{
    makeCurrent();
    cleanup();
}

void SceneWidget::selectCamera()
{
    pDrivenObject = pCamera;
}

void SceneWidget::setDirInt(float intensity)
{
    pDirLight->intensity = intensity;
}

void SceneWidget::setDirColor(const QColor& color)
{
    pDirLight->color = getGlColor(color);
}

void SceneWidget::setPointConst(float constant)
{
    pPointLight->constFactor = constant;
}

void SceneWidget::setPointLin(float linear)
{
    pPointLight->linFactor = linear;
}

void SceneWidget::setPointQuad(float quadric)
{
    pPointLight->quadFactor = quadric;
}

void SceneWidget::setPointInt(float intensity)
{
    pPointLight->intensity = intensity;
}

void SceneWidget::setPointColor(const QColor& color)
{
    pPointLight->color = getGlColor(color);
}

void SceneWidget::setSpotConst(float constant)
{

}

void SceneWidget::setSpotLin(float linear)
{

}

void SceneWidget::setSpotQuad(float quadric)
{

}

void SceneWidget::setSpotInt(float intensity)
{

}

void SceneWidget::setSpotColor(const QColor& color)
{
    pSpotLight->color = getGlColor(color);
}

void SceneWidget::setCutOff(float cutOff)
{

}

void SceneWidget::setOuterCutOff(float outerCutOff)
{

}

void SceneWidget::setObjectMaterial(int index)
{
    baseMaterial = MaterialFactory::make(index);
    *pMaterial = baseMaterial;
    pMaterial->ambient *= ambientFac;
    pMaterial->diffuse *= diffuseFac;
    pMaterial->specular *= specularFac;

    emit MaterialShininess(pMaterial->shininess);
}

void SceneWidget::selectPointLight()
{
    pDrivenObject = pPointLight;
}

void SceneWidget::setGridSteps(int steps)
{
    pObjectsGrid->setColums(steps);
    pObjectsGrid->setRows(steps);
}

void SceneWidget::setGridStepLen(float length)
{
    pObjectsGrid->setStepLength(length);
}

void SceneWidget::setMaterialAmbient(float val)
{
    ambientFac = val;
    pMaterial->ambient = baseMaterial.ambient * val;
}

void SceneWidget::setMaterialDiffuse(float val)
{
    diffuseFac = val;
    pMaterial->diffuse = baseMaterial.diffuse * val;
}

void SceneWidget::setMaterialSpecular(float val)
{
    specularFac = val;
    pMaterial->specular = baseMaterial.specular * val;
}

void SceneWidget::setMaterialShininess(float val)
{
    pMaterial->shininess = val;
}

void SceneWidget::setDirDirection(QVector3D dir)
{
    pDirLight->direction = dir;
}

void SceneWidget::cleanup()
{
    scene.clean();
    pCamera.reset();
    pDrivenObject.reset();
    pPointLight.reset();

}

void SceneWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton){
        mouseLastPosition = QVector2D(e->pos());
    }
}

void SceneWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton){
        QVector2D diff = QVector2D(event->pos()) - mouseLastPosition;
        diff *= 0.001f;
        pCamera->rotate(diff.x(), diff.y());
    }
    mouseLastPosition = QVector2D(event->pos());
}

void SceneWidget::keyPressEvent(QKeyEvent* event)
{
    keyboard.setKeyState(event->key(), true);
}

void SceneWidget::keyReleaseEvent(QKeyEvent* event)
{
    keyboard.setKeyState(event->key(), false);
}

void SceneWidget::moveProcess(float deltaTime)
{
    float length = cameraSpeed * deltaTime;
    QVector3D direction;

    if (keyboard[Qt::Key_W]){
        direction += forward;
    }
    if (keyboard[Qt::Key_S]){
        direction += backward;
    }
    if (keyboard[Qt::Key_D]){
        direction += rightward;
    }
    if (keyboard[Qt::Key_A]){
        direction += leftward;
    }
    if (keyboard[Qt::Key_Space]){
        direction += upward;
    }
    if (keyboard[Qt::Key_Z]){
        direction += downward;
    }
    pDrivenObject->offsetMove(direction * length);
    pSpotLight->moveTo(pCamera->cameraPosition());
    pSpotLight->setDirection(pCamera->front());
}

void SceneWidget::wheelEvent(QWheelEvent* ev)
{
    fov += ev->angleDelta().y() / 60.f;
    fov = std::clamp(fov, 10.f, 150.f);
}

void SceneWidget::timerEvent(QTimerEvent*)
{
    moveProcess(deltaTimeMsec / 1000.f); // deltaTime in sec
    update();
}

QSize SceneWidget::minimumSizeHint() const
{
    return {640, 480};
}

void SceneWidget::initShaders()
{
    Q_ASSERT(pObjectShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/GuroSceneObject.vert"));
    Q_ASSERT(pObjectShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GuroSceneObject.frag"));
    Q_ASSERT(pObjectShader->link());

    Q_ASSERT(pLightShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/LightSource.vert"));
    Q_ASSERT(pLightShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GuroSceneObject.frag"));
    Q_ASSERT(pLightShader->link());
}

void SceneWidget::setBackGroundColor()
{
    glClearColor(
                pDirLight->color.x() * pDirLight->intensity,
                pDirLight->color.y() * pDirLight->intensity,
                pDirLight->color.z() * pDirLight->intensity,
                1.f
                );
}

void SceneWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.f, 0.f, 0.f, 1.f);
    initShaders();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    scene.initialize(pObjectShader, pLightShader);

    QMatrix4x4 model;
    auto baseObject = std::make_shared<SceneObject>(
                          MeshFactory::makeCube({1, 1, 1}, GridSteps),
                          model,
                          pMaterial
                          );

    auto copy = baseObject->clone();
    copy->offsetMove({4, 0, 0});

    pObjectsGrid = std::make_shared<ObjectsGrid>(baseObject, GridStepLength, 4, 4);
    scene.addRenderObject(pObjectsGrid);
    model.setToIdentity();
    model.translate(0.f, 0.f, 2.f);
    pPointLight = std::make_shared<PointLightSource>(
                      MeshFactory::makeCube({0.1, 0.1, 0.1f}),
                      model, QVector3D{1.f, 1.f, 1.f}, 2.f
                      );

    scene.addPointLightSource(pPointLight);
    pDirLight = std::make_shared<DirecltyLight>(QVector3D(1, 1, 1), DirLightIntensity, DirLightDirection);
    scene.addDirectlyLightSource(pDirLight);

    pSpotLight = std::make_shared<SpotLightSource>(pCamera->cameraPosition(), pCamera->front());
    scene.addSpotLightSource(pSpotLight);

    pCamera->setZNear(zNear);
    pCamera->setZFar(zFar);
    timer.start(deltaTimeMsec, this);

    emit MaterialShininess(pMaterial->shininess);

    for (auto& [index, name] : MaterialFactory::names){
        emit newMaterial(name);
    }
}

void SceneWidget::resizeGL(int w, int h)
{
    pCamera->setAspectRatio(float(w) / float(h ? h : 1));
}

void SceneWidget::paintGL()
{
    setBackGroundColor();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pCamera->setFOV(fov);

    pObjectShader->bind();
    pObjectShader->setUniformValue("projView",pCamera->getProjViewMatrix());
    pObjectShader->setUniformValue("cameraPos", pCamera->cameraPosition());

    pLightShader->bind();
    pLightShader->setUniformValue("projView",pCamera->getProjViewMatrix());
    pLightShader->setUniformValue("cameraPos", pCamera->cameraPosition());

    scene.renderAll();
}

