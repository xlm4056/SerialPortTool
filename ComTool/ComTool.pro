#-------------------------------------------------
#
# Project created by QtCreator 2017-11-20T10:12:03
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network
RC_FILE   = ComTool.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComTool
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    helpinfo.cpp \
    crctool.cpp \
    outputthread.cpp \
    notetool.cpp \
    remotemaptool.cpp

HEADERS  += widget.h \
    head.h \
    helpinfo.h \
    crctool.h \
    outputthread.h \
    notetool.h \
    remotemaptool.h

RESOURCES += \
    images.qrc
