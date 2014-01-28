#include "noskin.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);

    NoSkin *f = new NoSkin();

    return app->exec();
}
