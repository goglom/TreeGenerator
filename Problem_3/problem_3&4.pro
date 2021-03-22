TEMPLATE = app
CONFIG += c++17
QT += core gui widgets
TARGET = Problem3_4


SOURCES += \
        cameraview.cpp \
        dialog.cpp \
        direcltylight.cpp \
        keyboard.cpp \
        main.cpp \
        mainwindow.cpp \
        meshfactory.cpp \
        meshobject.cpp \
        objectsgrid.cpp \
        pointlightsource.cpp \
        scene.cpp \
        sceneobject.cpp \
        scenewidget.cpp \
        spotlightsource.cpp

RESOURCES += \
    shaders.qrc

FORMS += \
    dialog.ui \
    mainwindow.ui

DISTFILES += \
    fshader.glsl \
    vshader.glsl

HEADERS += \
    cameraview.hpp \
    dialog.hpp \
    direcltylight.hpp \
    keyboard.hpp \
    lightsource.hpp \
    mainwindow.hpp \
    material.hpp \
    materialfactory.hpp \
    mesh.hpp \
    meshfactory.hpp \
    meshobject.hpp \
    object.hpp \
    objectsgrid.hpp \
    pointlightsource.hpp \
    renderobject.hpp \
    scene.hpp \
    sceneobject.hpp \
    scenewidget.hpp \
    spotlightsource.hpp \
    vertex.hpp
