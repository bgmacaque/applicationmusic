#include "fret.h"

Fret::Fret(int p_number, Note *p_note){
    m_number = p_number;
    m_note = p_note;
}

int Fret::getNumber() const{
    return m_number;
}

Note *Fret::getNote() const{
    return m_note;
}
