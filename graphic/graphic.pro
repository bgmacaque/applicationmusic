HEADERS += \
    noskin.h


SOURCES += \
    noskin.cpp \
    test.cpp

QT += core gui
QT += webkit
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
