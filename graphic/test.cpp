#include "noskin.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    NoSkin *f = new NoSkin();

    return app.exec();
}

