#include "noskin.h"
#include "controller.h"

#include "configuration.h"
#include <QLayout>
#include <iostream>
#include "notes.h"
#include "fret.h"
#include "guitar.h"
#include <QTextCodec>
using namespace std;


int main(int argc, char **argv)
{


    //Change the charset for all messages and QStrings
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication *app = new QApplication(argc, argv);
    NoSkin *frame = new NoSkin(400, 302);
    Controller *c = new Controller(frame);
    c->active();
    app->exec();
    delete c;


    Notes::kill();
    Guitar::kill();
    return 0;
}
