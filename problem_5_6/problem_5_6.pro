TEMPLATE = app
CONFIG += c++17
QT += core gui widgets
TARGET = Problem5_6


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
    cameraview.hpp \
    dialog.hpp \
    dialog.hpp \
    direcltylight.hpp \
    direcltylight.hpp \
    glcolor.hpp \
    glcolor.hpp \
    keyboard.hpp \
    keyboard.hpp \
    lightsource.hpp \
    lightsource.hpp \
    mainwindow.hpp \
    mainwindow.hpp \
    material.hpp \
    material.hpp \
    materialfactory.hpp \
    materialfactory.hpp \
    materialobject.hpp \
    materialobject.hpp \
    mesh.hpp \
    mesh.hpp \
    meshfactory.hpp \
    meshfactory.hpp \
    meshobject.hpp \
    meshobject.hpp \
    object.hpp \
    object.hpp \
    objectsgrid.hpp \
    objectsgrid.hpp \
    pointlightsource.hpp \
    pointlightsource.hpp \
    renderobject.hpp \
    renderobject.hpp \
    renderobjectdecorator.hpp \
    renderobjectdecorator.hpp \
    scene.hpp \
    scene.hpp \
    scenewidget.hpp \
    scenewidget.hpp \
    spotlightsource.hpp \
    spotlightsource.hpp \
    texture.hpp \
    texture.hpp \
    texturedobject.hpp \
    texturedobject.hpp \
    vertex.hpp \
    vertex.hpp
