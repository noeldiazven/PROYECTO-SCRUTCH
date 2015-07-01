#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T00:00:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pa
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    mover.cpp \
    gato.cpp \
    angulo.cpp \
    ventana.cpp \
    unicadireccion.cpp \
    bloques.cpp \
    inicio.cpp \
    for.cpp \
    ventanabotones.cpp \
    ventanamostrador.cpp \
    botones.cpp \
    girarderecha.cpp \
    posicionargatoen.cpp \
    rebote.cpp \
    botoncomenzar.cpp \
    if.cpp

HEADERS  += \
    mover.h \
    gato.h \
    angulo.h \
    ventana.h \
    unicadireccion.h \
    bloques.h \
    inicio.h \
    for.h \
    ventanabotones.h \
    ventanamostrador.h \
    tipos.h \
    botones.h \
    imagenes.h \
    girarderecha.h \
    posicionargatoen.h \
    rebote.h \
    botoncomenzar.h \
    if.h

FORMS    +=

RESOURCES += \
    image.qrc
