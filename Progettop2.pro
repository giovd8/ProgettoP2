QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progettop2

TEMPLATE = app

CONFIG += c++11

ICON = cucu.icns

SOURCES += main.cpp \
    gerarchia/piattobase.cpp \
    gerarchia/primo.cpp \
    gerarchia/secondo.cpp \
    gerarchia/contorno.cpp \
    gui/controller.cpp \
    gui/menuprincipale.cpp \
    gui/modifichedati.cpp \
    modello.cpp \
    gui/viewpiatti.cpp \
    gui/listapcontainer.cpp \
    gui/elementilistap.cpp \
    gui/inserimentopiatto.cpp \
    gui/modificapiatto.cpp \
    gui/cercapiatto.cpp

HEADERS += \
    gerarchia/piattobase.h \
    gerarchia/primo.h \
    gerarchia/secondo.h \
    gerarchia/contorno.h \
    gerarchia/container.h \
    gui/controller.h \
    gui/menuprincipale.h \
    gui/modifichedati.h \
    modello.h \
    gui/viewpiatti.h \
    gui/listapcontainer.h \
    gui/elementilistap.h \
    gui/inserimentopiatto.h \
    gui/modificapiatto.h \
    gui/cercapiatto.h

RESOURCES += \
    dataresource.qrc

