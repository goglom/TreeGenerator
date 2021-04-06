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
        materialobject.cpp \
        meshfactory.cpp \
        meshobject.cpp \
        objectsgrid.cpp \
        pointlightsource.cpp \
        scene.cpp \
        scenewidget.cpp \
        spotlightsource.cpp \
        texture.cpp \
        texturedobject.cpp

RESOURCES += \
    Resources.qrc

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
    glcolor.hpp \
    keyboard.hpp \
    lightsource.hpp \
    mainwindow.hpp \
    material.hpp \
    materialfactory.hpp \
    materialobject.hpp \
    mesh.hpp \
    meshfactory.hpp \
    meshobject.hpp \
    object.hpp \
    objectsgrid.hpp \
    pointlightsource.hpp \
    renderobject.hpp \
    renderobjectdecorator.hpp \
    scene.hpp \
    scenewidget.hpp \
    spotlightsource.hpp \
    texture.hpp \
    texturedobject.hpp \
    vertex.hpp
