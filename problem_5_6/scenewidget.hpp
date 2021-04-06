#pragma once

#define _ISC_ inline static constexpr

#include "cameraview.hpp"
#include "meshfactory.hpp"
#include "materialfactory.hpp"
#include "scene.hpp"
#include "materialobject.hpp"
#include "direcltylight.hpp"
#include "pointlightsource.hpp"
#include "keyboard.hpp"
#include "objectsgrid.hpp"
#include "texture.hpp"
#include "texturedobject.hpp"

#include <QElapsedTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QBasicTimer>

template<class T>
using sPtr = std::shared_ptr<T>;

class SceneWidget : public QOpenGLWidget
{
Q_OBJECT

public:
    SceneWidget() = delete;
    SceneWidget(QWidget* parent = nullptr);
    ~SceneWidget();

signals:
    void newMaterial(QString const&);
    void fpsChanged(int);
    void widgetClosed(void);

public slots:
    void selectCamera();
    void selectPointLight();
    void setGridSteps(int steps);
    void setGridStepLen(float length);
    void setAmbientColor(QColor const& color);
    void setDirDirection(QVector3D dir);
    void setDirInt(float intensity);
    void setDirColor(QColor const& color);
    void setPointConst(float constant);
    void setPointLin(float linear);
    void setPointQuad(float quadric);
    void setPointInt(float intensity);
    void setPointColor(QColor const& color);
    void setSpotConst(float constant);
    void setSpotLin(float linear);
    void setSpotQuad(float quadric);
    void setSpotInt(float intensity);
    void setSpotColor(QColor const& color);
    void setCutOff(float cutOff);
    void setOuterCutOff(float outerCutOff);
    void setObjectMaterial(int index);

public:
    OpenGLFunctionsSPtr pFunc =
            std::make_shared<QOpenGLFunctions>();

    void cleanup();
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent *ev) override;
    void closeEvent(QCloseEvent* event) override;
    void timerEvent(QTimerEvent *e) override;
    QSize minimumSizeHint() const override;
    void initializeGL() override;
    void initTextures();
    void initShaders();
    void initScene();
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void moveProcess();
    void setBackGroundColor();

    _ISC_ int initSteps = 8;
    _ISC_ float initFov = 60.f;
    _ISC_ float zNear = 0.1;
    _ISC_ float zFar = 300000.;
    _ISC_ std::size_t maxKeyCode = 0xff;
    _ISC_ unsigned deltaTimeMsec = 12;
    _ISC_ QVector3D forward{0.f, 0.f, 1.f};
    _ISC_ QVector3D upward{0.f, 1.f, 0.f};
    _ISC_ QVector3D rightward{1.f, 0.f, 0.f};
    _ISC_ QVector3D backward = -forward;
    _ISC_ QVector3D leftward = -rightward;
    _ISC_ QVector3D downward = -upward;
    _ISC_ size_t GridSteps = 1;
    _ISC_ float GridStepLength = 1.5f;
    _ISC_ float DirLightIntensity = 0.1;
    _ISC_ QVector3D DirLightDirection{0, -1, 0};
    _ISC_ QVector3D ambientColor = {0.01f, 0.01f, 0.01f};
    _ISC_ QVector3D dirLightColor = {0.0f, 0.0f, 0.0f};
    _ISC_ QVector3D pointLightColor = {1.f, 1.f, 1.f};
    _ISC_ QVector3D spotLightColor = {0.0f, 0.0f, 0.0f};

    Keyboard keyboard{Qt::Key_W, Qt::Key_A, Qt::Key_S, Qt::Key_D, Qt::Key_Control, Qt::Key_Space,
                     Qt::Key_Shift};


    Material baseMaterial = MaterialFactory::YellowRubber;
    sPtr<Material> pMaterial = std::make_shared<Material>(baseMaterial);
    float ambientFac = 1.f;
    float diffuseFac = 1.f;
    float specularFac = 1.f;
    sPtr<DirecltyLightSource> pDirLight{};
    sPtr<ObjectsGrid> pObjectsGrid{};
    sPtr<PointLightSource> pPointLight{};
    QVector3D pointLightPos{200, 0, 0};
    float fov = initFov;
    sPtr<SpotLightSource> pSpotLight{};
    sPtr<Texture> pEarthTexture = {};
    sPtr<Texture> pEarthNormalMap = {};
    sPtr<Texture> pSunTexture = {};
    sPtr<QOpenGLShaderProgram> pObjectShader =
            std::make_shared<QOpenGLShaderProgram>();
    sPtr<QOpenGLShaderProgram> pLightShader =
            std::make_shared<QOpenGLShaderProgram>();

    Scene scene;
    sPtr<CameraView> pCamera
        = std::make_shared<CameraView>(
              QVector3D{2.f, 0.f, 2.f},
              QVector3D{-1.f, 0.f, -1.f}
              );

    sPtr<Object> pDrivenObject
        = std::static_pointer_cast<Object>(pCamera);

    float cameraSpeed = 5.0;
    float pointLightAngluarSpeed = 10.f;

    QVector2D mouseLastPosition;
    int framesCount = 0;
    float deltaTime = 0.f;
    QElapsedTimer fpsTimer;
    QElapsedTimer deltaTimer;
    QBasicTimer timer;
};
