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
//    FModInit *fmodlib = new FModInit();
//    fmodlib->init();
    int i(0);
    Analyze *a = new Analyze();
//    a->init(fmodlib->getSystem(), fmodlib->getSound());
    float spectrum[16] = {
        64.5, 5.0, 10.6, 12.7, 13.0, 15.0, 9.0, 8.0, 3.0, 2.0, 32.0, 1.0, 48.0, 54.0, 12.3, 89.0
    };

    int places[16];
    for( i = 0 ; i < 16 ; i++){
        places[i] = i;
    }
    a->sort(places, spectrum, 0, 15);
    for( i = 0 ; i < 16 ; i ++){
        cout << "Place : " << places[i] << ", fréq : " << spectrum[places[i]] << endl;
    }
//    delete spectrum;
    delete a;
//    delete fmodlib;
    return 0;
}
