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
//    Partition *p = new Partition();
    Analyze *a = new Analyze();
    FModInit *fmodlib = new FModInit();
    fmodlib->init();
    int diff(0);
    int i(0);
    for(i = 0 ; i < 5000 ; i++){
        a->mainNote(fmodlib->getSystem(), fmodlib->getSound(), &diff);
        cout << "Différence : " << diff << endl;
    }
    delete fmodlib;
    delete a;
//    Chord *c = new Chord();
//    Note *n = new Note("A4", 440.0);
//    Note *n2 = a->getNote(1337.0);

//    c->addNote(n);
//    c->addNote(n2);
////    c->setDuration(10.0);
////    c->setVolume(5.0);
////    cout << c->save() << endl;
//    p->addChord(c);
//    Chord *c2 = new Chord();
//    c2->addNote(n);
//    p->addChord(c2);
//    string path = "./partition.kebab";
//    p->save(path.c_str());
//    delete p;
//    p = Partition::load(path.c_str());
//    delete c;
//    delete n;
//    delete a;
//    delete n2;
//    delete p;
//    delete c2;
    return 0;
}

