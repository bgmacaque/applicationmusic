HEADERS += \
    noskin.h \
    controller.h


SOURCES += \
    noskin.cpp \
    test.cpp \
    controller.cpp

QT += core gui
QT += webkit
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
