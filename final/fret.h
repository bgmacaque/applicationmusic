#ifndef FRET_H
#define FRET_H
#include "note.h"

/*!
 * \class Fret fret.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class provide the Fret structure common to every guitar
 * \brief The attribut m_number is the number of the fret on the guitar handle
 * \brief The attribut m_note is the note played on this fret
 */
class Fret{

private:

    int m_number;
    Note *m_note;
    int m_indexString;

public:
    Fret(int p_number, Note *p_note, int p_indexString);
    /*!
     * \brief Getter of number
     */
    int getNumber() const;

    /*!
     * \brief Getter of the note
     */
    Note *getNote() const;

    /*!
     * \brief Getter of the indexString
     */
    int getIndexString() const;
};

#endif // FRET_H
