QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progettop2
TEMPLATE = app

#TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    piattobase.cpp \
    primo.cpp \
    secondo.cpp \
    contorno.cpp \
    controller.cpp \
    menuprincipale.cpp \
    modifichedati.cpp \
    modello.cpp \
    viewpiatti.cpp \
    listapcontainer.cpp \
    elementilistap.cpp \
    inserimentopiatto.cpp \
    modificapiatto.cpp \
    cercapiatto.cpp

HEADERS += \
    piattobase.h \
    primo.h \
    secondo.h \
    contorno.h \
    container.h \
    controller.h \
    menuprincipale.h \
    modifichedati.h \
    modello.h \
    viewpiatti.h \
    listapcontainer.h \
    elementilistap.h \
    inserimentopiatto.h \
    modificapiatto.h \
    cercapiatto.h

