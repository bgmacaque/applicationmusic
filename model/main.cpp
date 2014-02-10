#include <iostream>
#include "note.h"
#include <vector>
#include "partition.h"
#include "chord.h"
#include "analyze.h"
#include "fmodinit.h"
using namespace std;

int main(int argc, char **argv)
{
    FModInit *fmodlib = new FModInit();
    fmodlib->init();
    Analyze *a = new Analyze();
    Note *note = new Note();
    a->init(fmodlib->getSystem(), fmodlib->getSound());
    usleep(200);
    int i = 0;
    float diff;
    for(i = 0 ; i < 50 ; i++){
        a->mainNote(note, &diff);
        cout << "Note : " << note->getDisplay();
        cout << ", différence : " << diff;
        cout << endl;
        usleep(1000 * 1000);
    }
    delete a;
    delete note;
    delete fmodlib;
    return 0;
}
