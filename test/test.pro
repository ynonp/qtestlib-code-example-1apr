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


SOURCES += tst_gamelogic.cpp ../gamelogic.cpp
HEADERS += ../gamelogic.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"
