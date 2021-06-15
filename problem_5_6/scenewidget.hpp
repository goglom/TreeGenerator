#pragma once

#define _ISC_ inline static constexpr

#include "cameraview.hpp"
#include "meshfactory.hpp"
#include "materialfactory.hpp"
#include "scene.hpp"
#include "direcltylight.hpp"
#include "keyboard.hpp"
#include "treebranch.hpp"
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
    void setAmbientColor(QColor const& color);
    void setDirDirection(QVector3D const& dir);
    void setDirInt(float intensity);
    void setDirColor(QColor const& color);
    void setObjectMaterial(int index);




public:
    void updateTree();
    void regrowTree();

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

    void initShaders();
    void initScene();
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void moveProcess();
    void setBackGroundColor();

    float fov = initFov;
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
    _ISC_ float DirLightIntensity = 1.f;
    _ISC_ QVector3D DirLightDirection{0, 0, 1};
    _ISC_ QVector3D ambientColor = {0.8f, 0.8f, 0.8f};
    _ISC_ QVector3D dirLightColor = {0.5f, 0.5f, 0.5f};
    bool regrowFlag = false;


    Keyboard keyboard{Qt::Key_W, Qt::Key_A, Qt::Key_S, Qt::Key_D,
                Qt::Key_Control, Qt::Key_Space, Qt::Key_Shift};
    Material baseMaterial = MaterialFactory::Chrome;
    sPtr<Material> pMaterial = std::make_shared<Material>(baseMaterial);
    float ambientFac = 1.f;
    float diffuseFac = 1.f;
    float specularFac = 1.f;

    sPtr<DirecltyLightSource> pDirLight{};
    sPtr<QOpenGLShaderProgram> pObjectShader = std::make_shared<QOpenGLShaderProgram>();
    sPtr<QOpenGLShaderProgram> pLightShader = std::make_shared<QOpenGLShaderProgram>();

    Scene scene;
    sPtr<CameraView> pCamera = std::make_shared<CameraView>(
              QVector3D{0.f, 10.f, -25.f}, QVector3D{0.f, 0.f, 1.f});

    sPtr<MovableObject> pDrivenObject = std::static_pointer_cast<MovableObject>(pCamera);
    float cameraSpeed = 8.0;
    QVector2D mouseLastPosition;
    int framesCount = 0;
    float deltaTime = 0.f;
    QElapsedTimer fpsTimer;
    QElapsedTimer deltaTimer;
    QBasicTimer frameUpdateTimer;


    std::unique_ptr<TreeBranch> tree = std::make_unique<TreeBranch>(0.6, 0.45, 2.5);
    RenderObjectSPtr treeModel;

    float treeFeedPortion = 1.f;
    size_t treeGrowCycles = 200;
    TreeBranch::Parametrs treeParams;


};
