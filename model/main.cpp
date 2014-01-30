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
    Analyze *a = new Analyze();
    delete a;
//    FModInit *fmodLib = new FModInit();
//    fmodLib->init();
//    a->mainNote(fmodLib->getSystem(), fmodLib->getSound());
//    Note *note = a->getNote(14000.0f);
//    cout << note->getDisplay() << endl;
//    Partition *p = new Partition();
//    Note n("A4",440);
//    vector<Note> *notes = new vector<Note>;
//    notes->push_back(n);
//    Chord *c = new Chord(*notes, 5, 6);
//    p->addChord(*c);
//    cout << p->getDisplay() << endl;
//    fmodLib->release();
    return 0;
}

