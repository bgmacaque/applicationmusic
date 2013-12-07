HEADERS += \
    noskin.h \
    notjsonexception.h \
    notconnected.h

SOURCES += \
    noskin.cpp \
    notjsonexception.cpp \
    notconnected.cpp

QT += core gui
QT += webkit
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
