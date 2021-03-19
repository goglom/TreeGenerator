TEMPLATE = app
CONFIG += c++17
QT += core gui widgets
TARGET = Problem3_4


SOURCES += \
        cameraview.cpp \
        cubewidget.cpp \
        direcltylight.cpp \
        keyboard.cpp \
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
    keyboard.hpp \
    lightsource.hpp \
    mainwindow.hpp \
    material.hpp \
    materialfactory.hpp \
    mesh.hpp \
    meshfactory.hpp \
    object.hpp \
    pointlightsource.hpp \
    renderobject.hpp \
    scene.hpp \
    sceneobject.hpp \
    vertex.hpp