#include "noskin.h"
#include "controller.h"

#include "configuration.h"
#include <QLayout>

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    NoSkin *frame = new NoSkin(600, 200);
    Controller *c = new Controller(frame);
    c->active();

    /*QMainWindow *main=  new QMainWindow();
    main->setMinimumHeight(300);
    main->setMinimumWidth(300);
    //GraphicNote *c = new GraphicNote(main, 12);
    GraphicScore *sc = new GraphicScore(5);
    QHBoxLayout *lay = new QHBoxLayout();
    lay->addWidget(sc);
    main->setLayout(lay);
    main->show();*/

    //Testing the creation of a config file
    //Configuration *test = new Configuration(new QString("Cémoi"), new QString("toto666"), false, true, 5);
    //test->save();

    return app->exec();
}
