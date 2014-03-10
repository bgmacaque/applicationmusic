TEMPLATE = app

SOURCES += noskin.cpp \
    test.cpp \
    controller.cpp \
    confwindow.cpp \
    configuration.cpp \
    dbconnection.cpp \
    graphicnote.cpp \
    graphicscore.cpp \
    positionnednote.cpp

HEADERS += noskin.h \
    controller.h \
    confwindow.h \
    configuration.h \
    dbconnection.h \
    graphicnote.h \
    graphicscore.h \
    positionnednote.h

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
