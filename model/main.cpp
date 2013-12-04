#include <iostream>
#include "note.h"

using namespace std;

int main()
{
    Note n("A4", 440);
    cout << n.getFrequency() << endl;
    return 0;
}

