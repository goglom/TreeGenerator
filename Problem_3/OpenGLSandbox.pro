TEMPLATE = app
CONFIG += c++17
QT += core gui widgets
LIBS += -lopengl32

TARGET = OpenGLSandbox


SOURCES += \
        cameraview.cpp \
        cubewidget.cpp \
        direcltylight.cpp \
        keyboardstate.cpp \
        main.cpp \
        mainwindow.cpp \
        materialfactory.cpp \
        meshfactory.cpp \
        pointlightsource.cpp \
        renderobject.cpp \
        scene.cpp \
        sceneobject.cpp

RESOURCES += \
    shaders.qrc

FORMS += \
    mainwindow.ui

DISTFILES += \
    fshader.glsl \
    vshader.glsl

HEADERS += \
    cameraview.hpp \
    cubewidget.hpp \
    direcltylight.hpp \
    keyboardstate.hpp \
    lightsource.hpp \
    mainwindow.hpp \
    material.hpp \
    materialfactory.hpp \
    mesh.hpp \
    meshfactory.hpp \
    pointlightsource.hpp \
    renderobject.hpp \
    scene.hpp \
    sceneobject.hpp \
    vertex.hpp
