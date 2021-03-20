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

#include "cubewidget.hpp"

#include <QMouseEvent>
#include <iostream>
#include <cmath>


CubeWidget::CubeWidget(QWidget* parent)
     : QOpenGLWidget(parent),
       scene(*this),
       keyStates(maxKeyCode, false)
{
}

CubeWidget::~CubeWidget()
{
    makeCurrent();
}

void CubeWidget::selectCamera()
{
    pDrivenObject = pCamera;
}

void CubeWidget::selectPointLights()
{
    pDrivenObject = pPointLightObject;
}

void CubeWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton){
        mouseLastPosition = QVector2D(e->pos());
    }
}

void CubeWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton){
        QVector2D diff = QVector2D(event->pos()) - mouseLastPosition;
        diff *= 0.001f;
        pCamera->rotate(diff.x(), diff.y());
    }
    mouseLastPosition = QVector2D(event->pos());
}

void CubeWidget::keyPressEvent(QKeyEvent* event)
{
    keyboard.setKeyState(event->key(), true);
}

void CubeWidget::keyReleaseEvent(QKeyEvent* event)
{
    keyboard.setKeyState(event->key(), false);
}

void CubeWidget::moveProcess(float deltaTime)
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
}

void CubeWidget::wheelEvent(QWheelEvent* ev)
{
    fov += ev->angleDelta().y() / 60.f;
    fov = std::clamp(fov, 10.f, 150.f);
}

void CubeWidget::timerEvent(QTimerEvent*)
{
    moveProcess(deltaTimeMsec / 1000.f); // deltaTime in sec
    update();
}

QSize CubeWidget::minimumSizeHint() const
{
    return {640, 480};
}

void CubeWidget::initShaders()
{
    Q_ASSERT(pObjectShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/GuroSceneObject.vert"));
    Q_ASSERT(pObjectShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GuroSceneObject.frag"));
    Q_ASSERT(pObjectShader->link());

    Q_ASSERT(pLightShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/LightSource.vert"));
    Q_ASSERT(pLightShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GuroSceneObject.frag"));
    Q_ASSERT(pLightShader->link());
}

void CubeWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.f, 0.f, 0.f, 1.f);
    initShaders();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    scene.initialize(pObjectShader, pLightShader);

    QMatrix4x4 model;
    auto baseObject = std::make_shared<SceneObject>(
                          MeshFactory::makeCube({1, 1, 1}, 20),
                          model,
                          MaterialFactory::makeGlod()
                          );

    auto copy = baseObject->clone();
    copy->offsetMove({4, 0, 0});


    //scene.addRenderObject(baseObject);
    //scene.addRenderObject(copy);


    auto grid = std::make_shared<ObjectsGrid>(baseObject, 2.f, 10, 10);
    scene.addRenderObject(grid);

    model.setToIdentity();
    model.translate(0.f, 0.f, 2.f);
    auto pointLightSource = std::make_shared<PointLightSource>(MeshFactory::makeCube({0.1, 0.1, 0.1f}),
                                                model, QVector3D{1.f, 1.f, 1.f}, 2.f);

    scene.addDirectlyLightSource(std::make_shared<DirecltyLight>(QVector3D(1, 1, 1), 0.1f, QVector3D(0, -1, 1)));

    scene.addPointLightSource(pointLightSource);


    model.setToIdentity();
    model.translate(0.f, 2.f, -3.f);



    pPointLightObject = scene.pointLightSources[pointLightObjectNum];


    pCamera->setZNear(zNear);
    pCamera->setZFar(zFar);
    timer.start(deltaTimeMsec, this);
}

void CubeWidget::resizeGL(int w, int h)
{
    pCamera->setAspectRatio(float(w) / float(h ? h : 1));
}

void CubeWidget::paintGL()
{
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

