TEMPLATE = app
INCLUDEPATH += "../"
LIBS += -L/../ -lfmodex

SOURCES += main.cpp \
    note.cpp \
    chord.cpp \
    partition.cpp \
    analyze.cpp \
    fmodinit.cpp \
    noskin.cpp \
    test.cpp \
    controller.cpp \
    confwindow.cpp \
    configuration.cpp \
    dbconnection.cpp \
    graphicnote.cpp \
    graphicscore.cpp \
    positionnednote.cpp \
    recordthread.cpp \
    guitarstring.cpp \
    notes.cpp \
    fret.cpp \
    guitar.cpp \
    tablature.cpp \
    frettedchord.cpp

HEADERS += \
    note.h \
    chord.h \
    partition.h \
    analyze.h \
    fmodinit.h \
    noskin.h \
    controller.h \
    confwindow.h \
    configuration.h \
    dbconnection.h \
    graphicnote.h \
    graphicscore.h \
    positionnednote.h \
    recordthread.h \
    guitarstring.h \
    notes.h \
    fret.h \
    guitar.h \
    tablature.h \
    frettedchord.h

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
