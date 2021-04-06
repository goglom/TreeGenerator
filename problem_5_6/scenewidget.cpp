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
#include "glcolor.hpp"

#include <QImage>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <iostream>
#include <cmath>


SceneWidget::SceneWidget(QWidget* parent)
     : QOpenGLWidget(parent)
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
    pSpotLight->constFactor = constant;
}

void SceneWidget::setSpotLin(float linear)
{
    pSpotLight->linFactor = linear;
}

void SceneWidget::setSpotQuad(float quadric)
{
    pSpotLight->quadFactor = quadric;
}

void SceneWidget::setSpotInt(float intensity)
{
    pSpotLight->intensity = intensity;
}

void SceneWidget::setSpotColor(const QColor& color)
{
    pSpotLight->color = getGlColor(color);
}

void SceneWidget::setCutOff(float cutOff)
{
    pSpotLight->cutOff = qDegreesToRadians(cutOff);
}

void SceneWidget::setOuterCutOff(float outerCutOff)
{

    pSpotLight->outerCutOff = qDegreesToRadians(outerCutOff);
}

void SceneWidget::setObjectMaterial(int index)
{
    baseMaterial = MaterialFactory::make(index);
    *pMaterial = baseMaterial;
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

void SceneWidget::setAmbientColor(const QColor& color)
{
    scene.setAmbientColor(color);
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

void SceneWidget::moveProcess()
{
    float length = cameraSpeed * deltaTime;
    QVector3D direction;

    if (keyboard[Qt::Key_Shift]){
        length *= 5.f;
    }
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
    if (keyboard[Qt::Key_Control]){
        direction += downward;
    }
    pDrivenObject->offsetMove(direction * length);
    pSpotLight->moveTo(pCamera->position());
    pSpotLight->setDirection(pCamera->front());

    QMatrix4x4 rotation;
    rotation.rotate(pointLightAngluarSpeed * deltaTime, QVector3D{0, 1, 0});
    pointLightPos = rotation * pointLightPos;
    pPointLight->moveTo(pointLightPos);

}

void SceneWidget::wheelEvent(QWheelEvent* ev)
{
    fov += ev->angleDelta().y() / 60.f;
    fov = std::clamp(fov, 10.f, 150.f);
}

void SceneWidget::closeEvent(QCloseEvent* )
{
    emit widgetClosed();
}

void SceneWidget::timerEvent(QTimerEvent*)
{
    moveProcess(); // deltaTime in sec
    update();
}

QSize SceneWidget::minimumSizeHint() const
{
    return {640, 480};
}

void SceneWidget::initShaders()
{
    if (!(    pObjectShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/FongSceneObject.vert")
          &&  pObjectShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/FongSceneObject.frag")
          &&  pLightShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/LightSource.vert")
          &&  pLightShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/LightSource.frag")
          &&  pLightShader->link())
    ){
        Q_ASSERT(false);
        close();
    }
}


void SceneWidget::initTextures()
{
    pEarthTexture = std::make_shared<Texture>(
                        QImage(":/Textures/Earth_Albedo.jpg"),
                        "textureMap"
                        );

    pEarthTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    pEarthTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    pEarthNormalMap = std::make_shared<Texture>(
                          QImage(":/Textures/Earth_NormalMap.jpg"),
                          "normalMap");

    pEarthNormalMap->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    pEarthNormalMap->setMagnificationFilter(QOpenGLTexture::Linear);

    pSunTexture = std::make_shared<Texture>(
                          QImage(":/Textures/Sun_texture.jpg"),
                          "textureMap");

    pSunTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    pSunTexture->setMagnificationFilter(QOpenGLTexture::Linear);
}

void SceneWidget::initScene()
{
    scene.initialize(pFunc, pObjectShader, pLightShader);

    scene.setAmbientColor(ambientColor);

    QMatrix4x4 model;
    auto baseObject = std::make_shared<MaterialObject>(
                          TexturedObject::construct(
                              TexturedObject::construct(
                                  MeshObject::construct(
                                      MeshFactory::makeSphere(10, 10)),
                                  pEarthNormalMap),
                              pEarthTexture),
                          pMaterial
                      );
    pObjectsGrid = std::make_shared<ObjectsGrid>(baseObject, GridStepLength, GridSteps, GridSteps);
    scene.addRenderObject(pObjectsGrid);
    model.setToIdentity();
    model.translate(pointLightPos);

    pPointLight = std::make_shared<PointLightSource>(
                      TexturedObject::construct(
                          MeshObject::construct(MeshFactory::makeSphere(50, 50, 20.f), model),
                          pSunTexture),
                      pointLightColor,
                      1.f,
                      0.6f,
                      0.0f,
                      0.0f
                      );

    scene.addPointLightSource(pPointLight);
    pDirLight = std::make_shared<DirecltyLightSource>(dirLightColor, DirLightIntensity, DirLightDirection);
    scene.addDirectlyLightSource(pDirLight);

    pSpotLight = std::make_shared<SpotLightSource>(pCamera->position(), pCamera->front(),
                                                   spotLightColor);
    scene.addSpotLightSource(pSpotLight);

    pCamera->setZNear(zNear);
    pCamera->setZFar(zFar);
}

void SceneWidget::setBackGroundColor()
{
    pFunc->glClearColor(
                scene.getAmbientColor().x(),
                scene.getAmbientColor().y(),
                scene.getAmbientColor().z(),
                1.f);
}

void SceneWidget::initializeGL()
{
    pFunc->initializeOpenGLFunctions();
    initShaders();
    initTextures();
    initScene();
    pFunc->glEnable(GL_DEPTH_TEST);
    pFunc->glEnable(GL_CULL_FACE);

    for (auto& [index, name] : MaterialFactory::names){
        emit newMaterial(name);
    }
    fpsTimer.start();
    deltaTimer.start();
    timer.start(deltaTimeMsec, this);
}


void SceneWidget::resizeGL(int w, int h)
{
    pCamera->setAspectRatio(float(w) / float(h ? h : 1));
}

void SceneWidget::paintGL()
{
    // ---------------- Render block ------------------------------------------
    setBackGroundColor();
    pFunc->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pCamera->setFOV(fov);

    pObjectShader->bind();
    pObjectShader->setUniformValue("projView",pCamera->getProjViewMatrix());
    pObjectShader->setUniformValue("cameraPos", pCamera->position());

    pLightShader->bind();
    pLightShader->setUniformValue("projView",pCamera->getProjViewMatrix());

    scene.renderAll();

    //-------------------------------------------------------------------------

    deltaTime = deltaTimer.elapsed() / 1000.f;
    deltaTimer.restart();

    framesCount++;
    if (fpsTimer.elapsed() > 1000){
        emit fpsChanged(framesCount + 1);
        framesCount = 0;
        fpsTimer.restart();
    }

}

