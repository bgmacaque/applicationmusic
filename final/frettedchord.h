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
    int m_numberFrets;
    int indexString;
    Chord *m_chord;
public:
    FrettedChord(Chord *c);
    ~FrettedChord();

    /*!
     * \brief Getter of m_frets
     */
    Fret **getFrets() const;

    /*!
     * \brief Getter of m_numberFrets
     */
    int getNumberFrets() const;

    /*!
     * \brief Getter of duration
     */
    float getDuration() const;

    QString stringify() const;

    static void parse(FileReader *fr);
};

#endif // FRETTEDCHORD_H
