TEMPLATE = app
CONFIG += console

LIBS += -lfmodex
INCLUDEPATH += "../model"

HEADERS += \
    noskin.h \
    controller.h \
    confwindow.h \
    configuration.h \
    dbconnection.h \
    ../model/partition.h \
    ../model/chord.h \
    ../model/note.h \


SOURCES += \
    noskin.cpp \
    test.cpp \
    controller.cpp \
    confwindow.cpp \
    configuration.cpp \
    dbconnection.cpp \
    ../model/partition.cpp \
    ../model/chord.cpp \
    ../model/note.cpp \


QT += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
