#include "graphicchord.h"
#include "graphicneedle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicChord w;

    w.sleep(300);

    w.setTo("A", 0);
    //w.goTo(100);

    w.sleep(300);
    w.setTo("D", 500);

    return a.exec();
}
