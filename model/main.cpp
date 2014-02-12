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
    Analyze *a = new Analyze();
    bool tune = true;
    p->record(a, &tune);
    delete a;
    delete p;
    return 0;
}
