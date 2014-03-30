#include "graphicchord.h"
#include "graphicneedle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraphicChord w(NULL, QString("A"));

    w.setTo("A", 0);
    w.setTo("B", 1);
    w.setTo("B", 1);
    w.setTo("C", -1);
    w.setTo("D", 0);
    w.setTo("D", 1);
    w.setTo("D", 0);
    w.setTo("C", -1);
    w.setTo("E", -1);
    w.setTo("A", 0);
    w.setTo("A", 1);
    w.setTo("E", -1);
    w.setTo("A", 0);
    w.setTo("A", 1);
    w.setTo("E", -1);
    w.setTo("A", 0);
    w.setTo("A", 1);
    w.setTo("E", -1);
    w.setTo("A", 0);

    return a.exec();
}
