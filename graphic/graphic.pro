INCLUDEPATH += "../"
INCLUDEPATH += "../model/"
TEMPLATE = app
CONFIG += console

#LIBS += -L/../ -lfmodex

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
    ../model/partition.cpp \
    ../model/chord.cpp \
    ../model/note.cpp \


QT += core gui
QT += webkit
QT += webkitwidgets
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
