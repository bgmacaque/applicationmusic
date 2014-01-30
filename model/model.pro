TEMPLATE = app
CONFIG += console
CONFIG -= qt
INCLUDEPATH += "/usr/include"
LIBS += -L/usr/lib -lfmodex

SOURCES += main.cpp \
    note.cpp \
    chord.cpp \
    partition.cpp \
    analyze.cpp \
    fmodinit.cpp

HEADERS += \
    note.h \
    chord.h \
    partition.h \
    analyze.h \
    fmodinit.h

