#include "graphicchord.h"
#include "graphicneedle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicChord w;

    //GraphicChord::sleep(1000);

    //w.goForward();

    w.sleep(300);

    w.setTo("A", 10);
    //w.goTo(100);

    //w.sleep(300);
    //w.setTo("D", 500);

    return a.exec();
}
