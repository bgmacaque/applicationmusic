#include "graphicchord.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicChord w;
    w.show();
    
    return a.exec();
}
