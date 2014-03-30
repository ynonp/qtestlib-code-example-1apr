#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T15:15:23
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_gamelogic
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += ../gamelogic.cpp \
    main.cpp \
    testgamelogic.cpp
HEADERS += ../gamelogic.h \
    testgamelogic.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"
