#include "noskin.h"
#include "controller.h"

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    NoSkin *frame = new NoSkin(600, 200);
    Controller *c = new Controller(frame);
    c->active();

    return app->exec();
}
