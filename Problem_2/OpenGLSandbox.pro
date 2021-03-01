TEMPLATE = app
CONFIG += c++17
QT += core gui widgets
LIBS += -lopengl32

TARGET = OpenGLSandbox


SOURCES += \
        cameraview.cpp \
        cube.cpp \
        cubewidget.cpp \
        main.cpp \
        mainwindow.cpp \
        rectflatgridsurface.cpp

RESOURCES += \
    shaders.qrc

FORMS += \
    mainwindow.ui

DISTFILES += \
    fshader.glsl \
    vshader.glsl

HEADERS += \
    cameraview.hpp \
    cube.hpp \
    cubewidget.hpp \
    globject.hpp \
    mainwindow.hpp \
    rectflatgridsurface.hpp
