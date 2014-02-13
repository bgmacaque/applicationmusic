#include "noskin.h"
#include "controller.h"

#include "configuration.h"

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    NoSkin *frame = new NoSkin(600, 200);
    Controller *c = new Controller(frame);
    c->active();

    //Testing the creation of a config file
    //Configuration *test = new Configuration(new QString("Cémoi"), new QString("toto666"), false, true, 5);
    //test->save();

    return app->exec();
}
