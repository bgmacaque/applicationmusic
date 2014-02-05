#include <iostream>
#include "note.h"
#include <vector>
#include "partition.h"
#include "chord.h"
#include "analyze.h"
#include "fmodinit.h"
using namespace std;

int main()
{
    Partition *p = new Partition();
    Chord *c = new Chord();
    Note *n = new Note("A4", 440.0);
    Note *n2 = new Note("A5", 550);
    c->addNote(n);
    c->addNote(n2);
//    c->setDuration(10.0);
//    c->setVolume(5.0);
    cout << c->save() << endl;
    p->addChord(c);
    string path = "./partition.kebab";
    p->save(path.c_str());
    delete c;
    delete n;
    delete n2;
    delete p;
//    Analyze *a = new Analyze();
////    Note *note = a->getNote(7000.0f);
////    cout << note->getDisplay() << endl;
////    delete a;

//    FModInit *fmodLib = new FModInit();
//    fmodLib->init();
//    a->mainNote(fmodLib->getSystem(), fmodLib->getSound());
////    delete fmodLib;
//    usleep(500*10000 + 300);
//    delete a;
//    delete fmodLib;

//    Partition *p = new Partition();
//     Note n("A4",440);
//    vector<Note> *notes = new vector<Note>;
//    notes->push_back(n);
//    Chord *c = new Chord(*notes, 5, 6);
//    p->addChord(*c);
//    cout << p->getDisplay() << endl;
//    fmodLib->release();
    return 0;
}

