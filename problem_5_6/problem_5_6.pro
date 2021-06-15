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
        meshcollectionobject.cpp \
        meshfactory.cpp \
        meshobject.cpp \
        scene.cpp \
        scenewidget.cpp \
        treebranch.cpp

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
    mesh.hpp \
    meshcollectionobject.hpp \
    meshfactory.hpp \
    meshobject.hpp \
    movableobject.hpp \
    renderobject.hpp \
    scene.hpp \
    scenewidget.hpp \
    treebranch.hpp \
    vertex.hpp \

unix|win32: LIBS += -L$$PWD/../../../../../../../assimp-5.0.1/build/code/ -lassimp

INCLUDEPATH += $$PWD/../../../../../../../assimp-5.0.1/build/include
DEPENDPATH += $$PWD/../../../../../../../assimp-5.0.1/build/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/code/assimp.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/code/libassimp.a

unix|win32: LIBS += -L$$PWD/../../../../../../../assimp-5.0.1/build/contrib/irrXML/ -lIrrXML

INCLUDEPATH += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/irrXML
DEPENDPATH += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/irrXML

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/irrXML/IrrXML.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/irrXML/libIrrXML.a

unix|win32: LIBS += -L$$PWD/../../../../../../../assimp-5.0.1/build/contrib/zlib/ -lzlibstatic

INCLUDEPATH += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/zlib
DEPENDPATH += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/zlib

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/zlib/zlibstatic.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../../../../../assimp-5.0.1/build/contrib/zlib/libzlibstatic.a
