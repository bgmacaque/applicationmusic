#include <iostream>
#include "note.h"
#include <vector>
#include "partition.h"
#include "chord.h"
#include "analyze.h"
using namespace std;

int main()
{
    Analyze *a = new Analyze();
    Note *note = a->getNote(8400.0f);
    cout << note->getDisplay() << endl;
    Partition *p = new Partition();
    Note n("A4",440);
    vector<Note> *notes = new vector<Note>;
    notes->push_back(n);
    Chord *c = new Chord(*notes, 5, 6);
    p->addChord(*c);
//    cout << p->getDisplay() << endl;
    return 0;
}

