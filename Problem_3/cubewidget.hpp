#pragma once

#define _ISC_ inline static constexpr

#include "cameraview.hpp"
#include "meshfactory.hpp"
#include "materialfactory.hpp"
#include "scene.hpp"
#include "sceneobject.hpp"
#include "direcltylight.hpp"
#include "pointlightsource.hpp"

#include <vector>
#include <unordered_map>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QBasicTimer>
#include <QColorDialog>


template<class T>
using sPtr = std::shared_ptr<T>;

class CubeWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT

public:

    CubeWidget() = delete;
    CubeWidget(QWidget* parent = nullptr);
    ~CubeWidget();

private:

    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent *ev) override;
    void timerEvent(QTimerEvent *e) override;
    QSize minimumSizeHint() const override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void moveProcess(float deltaTime);
    void initShaders();

    _ISC_ int initSteps = 8;
    _ISC_ float initFov = 60.f;
    _ISC_ float zNear = 0.1;
    _ISC_ float zFar = 100.;
    _ISC_ std::size_t maxKeyCode = 0xff;
    _ISC_ unsigned deltaTimeMsec = 16;

    _ISC_ QVector3D forward{0.f, 0.f, 1.f};
    _ISC_ QVector3D upward{0.f, 1.f, 0.f};
    _ISC_ QVector3D rightward{1.f, 0.f, 0.f};
    _ISC_ QVector3D backward = -forward;
    _ISC_ QVector3D leftward = -rightward;
    _ISC_ QVector3D downward = -upward;


    sPtr<QOpenGLShaderProgram> pObjectShader =
            std::make_shared<QOpenGLShaderProgram>();
    sPtr<QOpenGLShaderProgram> pLightShader =
            std::make_shared<QOpenGLShaderProgram>();

    Scene scene;
    sPtr<CameraView> pCamera
        = std::make_shared<CameraView>(QVector3D{0.f, 0.f, 5.f});

    sPtr<Object> pDrivenObject
        = std::static_pointer_cast<Object>(pCamera);

    float cameraSpeed = 3.0;

    float aspectRatio;
    float fov = initFov;
    QVector2D mouseLastPosition;
    std::vector<bool> keyStates;

    QBasicTimer timer;
};
