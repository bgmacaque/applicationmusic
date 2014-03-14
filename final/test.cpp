#include "noskin.h"
#include "controller.h"

#include "configuration.h"
#include <QLayout>
#include <iostream>
#include "notes.h"

#include "guitar.h"
using namespace std;


int main(int argc, char **argv)
{
    bool error;
    Partition *p = Partition::load("./partition.tab", &error);
    cout << error << endl;
    delete p;
//    Partition *p = new Partition(240, 0.025, 0.075);
//    p->setName("COUCOU");
//    Note *n = new Note("A4", 440);
//    Chord *chord = new Chord();
//    Note *n2 = new Note("A5", 880);
//    chord->addNote(n2);
//    chord->setVolume(0.7586);
//    chord->setDuration(0.76546);
//    chord->addNote(n);
//    p->addChord(chord);
//    p->addChord(chord);
//    p->save("./partition.tab");
//    cout << p->stringify().toStdString() << endl;
//    delete chord;
//    delete n;
//    delete p;
//    Notes *notes = Notes::get_instance();
//    cout << notes->searchNote("E6")->getFrequency() << endl;
//    Notes::kill();
//    Guitar *g = Guitar::get_instance();
//    GuitarString *gs = new GuitarString("E", "E3", 25);
//    Note *n = new Note("A4", 440.0);
////    cout << gs->playable(n) << endl;
//    Partition *p = new Partition(240, 0.025, 0.025);
//    Chord *c = new Chord();
//    c->addNote(n);
//    p->addChord(c);


//    delete n;
//    delete c;
//    delete p;
//    delete gs;
//    Notes::kill();
//    Guitar::kill();
//    delete gs;



    //    for( ; ; ){

//    }
//    QApplication *app = new QApplication(argc, argv);
//    NoSkin *frame = new NoSkin(600, 200);
//    Controller *c = new Controller(frame);
//    c->active();

//    QMainWindow *main=  new QMainWindow();
//    main->setMinimumHeight(300);
//    main->setMinimumWidth(300);
//    GraphicNote *c = new GraphicNote(main, 12);
//    GraphicScore *sc = new GraphicScore(5);
//    QHBoxLayout *lay = new QHBoxLayout();
//    lay->addWidget(sc);
//    main->setLayout(lay);
//    main->show();

    //Testing the creation of a config file
    //Configuration *test = new Configuration(new QString("Cémoi"), new QString("toto666"), false, true, 5);
    //test->save();
    return 0;
//    return app->exec();
}
