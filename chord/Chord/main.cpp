#include "graphictuner.h"
#include "graphicneedle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraphicTuner w(NULL, QString("A"));

    w.setTo(QString("A"), 0);
    w.setTo(QString("B"), 1);
    w.setTo(QString("B"), 1);
    w.setTo(QString("C"), -1);
    w.setTo(QString("D"), 0);
    w.setTo(QString("D"), 1);
    w.setTo(QString("D"), 0);
    w.setTo(QString("C"), -1);
    w.setTo(QString("E"), -1);
    w.setTo(QString("A"), 0);
    w.setTo(QString("A"), 1);
    w.setTo(QString("E"), -1);
    w.setTo(QString("A"), 0);
    w.setTo(QString("A"), 1);
    w.setTo(QString("E"), -1);
    w.setTo(QString("A"), 0);
    w.setTo(QString("A"), 1);
    w.setTo(QString("E"), -1);
    w.setTo(QString("A"), 0);

    return a.exec();
}
