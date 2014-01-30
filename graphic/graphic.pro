HEADERS += \
    noskin.h \
    controller.h \
    confwindow.h \
    configuration.h


SOURCES += \
    noskin.cpp \
    test.cpp \
    controller.cpp \
    confwindow.cpp \
    configuration.cpp

QT += core gui
QT += webkit
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
