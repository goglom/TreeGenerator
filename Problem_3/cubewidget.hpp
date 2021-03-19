#pragma once

#include "cameraview.hpp"
#include "meshfactory.hpp"
#include "materialfactory.hpp"
#include "scene.hpp"
#include "sceneobject.hpp"
#include "direcltylight.hpp"
#include "pointlightsource.hpp"

#include <vector>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QBasicTimer>
#include <QColorDialog>

class CubeWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT

public:

    CubeWidget() = delete;
    CubeWidget(QWidget* parent = nullptr);
    ~CubeWidget();


protected:
    inline static constexpr int initSteps = 8;
    inline static constexpr float initFov = 60.f;
    inline static constexpr float zNear = 0.1;
    inline static constexpr float zFar = 100.;
    inline static constexpr std::size_t maxKeyCode = 0xff;
    inline static constexpr unsigned deltaTimeMsec = 16;

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


private:
    std::shared_ptr<QOpenGLShaderProgram> objShader =
            std::make_shared<QOpenGLShaderProgram>();
    std::shared_ptr<QOpenGLShaderProgram> lightShader =
            std::make_shared<QOpenGLShaderProgram>();

    Scene scene;
    CameraView camera{{0.f, 0.f, 5.f}};
    float cameraSpeed = 3.0;

    float aspectRatio;
    float fov = initFov;
    QVector2D mouseLastPosition;
    std::vector<bool> keyStates;

    QBasicTimer timer;
};
