#include "graphicchord.h"
#include "graphicneedle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //GraphicNeedle w(NULL, 300, 150);
    GraphicChord w;

    //GraphicChord::sleep(1000);

    //w.goLeft();
    std::string e;


    //w.sleep(300);
    //w.goLeft();

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
    //w.goTo(100);
   // w.setTo("D", 1);

    //w.sleep(300);
    //w.setTo("D", 500);

    return a.exec();
}
