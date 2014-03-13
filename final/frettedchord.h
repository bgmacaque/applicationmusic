#ifndef FRETTEDCHORD_H
#define FRETTEDCHORD_H
#include "fret.h"
#include "chord.h"
#include "guitar.h"

class FrettedChord{
private:
    Fret **m_frets;

public:
    FrettedChord(Chord *c);
    Fret **getFrets();
};

#endif // FRETTEDCHORD_H
