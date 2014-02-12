TEMPLATE = app
CONFIG += console

HEADERS += \
    noskin.h \
    controller.h \
    confwindow.h \
    configuration.h \
    dbconnection.h \


SOURCES += \
    noskin.cpp \
    test.cpp \
    controller.cpp \
    confwindow.cpp \
    configuration.cpp \
    dbconnection.cpp \


QT += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
