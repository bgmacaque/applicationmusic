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
    Partition *p = new Partition(120);
    FModInit *fmodlib = new FModInit();
    Analyze *a = new Analyze(fmodlib->getSystem(), fmodlib->getSound());

    bool tune = true;
    p->record(a, &tune);

    delete a;
    delete fmodlib;
    delete p;
    return 0;
}
