#ifndef FRETTEDCHORD_H
#define FRETTEDCHORD_H
#include "fret.h"
#include "chord.h"
#include "guitar.h"

/*!
 * \class Frettedchord frettedchord.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represent the frets that are pressed to play the chord
 * \brief The attribut **m_frets represent an array of the frets that are pressed
 */\

class FrettedChord{
private:
    Fret **m_frets;

public:
    FrettedChord(Chord *c);
    Fret **getFrets();
};

#endif // FRETTEDCHORD_H
