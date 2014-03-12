#ifndef FRET_H
#define FRET_H
#include "note.h"

class Fret{

private:

    int m_number;
    Note *m_note;

public:
    Fret(int p_number, Note *p_note);
    int getNumber() const;
    Note *getNote() const;
};

#endif // FRET_H
