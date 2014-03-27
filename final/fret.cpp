#include "fret.h"
#include <iostream>

Fret::Fret(int p_number, Note *p_note, int p_indexString){
    m_number = p_number;
    m_note = p_note;
    m_indexString = p_indexString;
//    std::cout << m_note->getDisplay() << std::endl;
}

int Fret::getNumber() const{
    return m_number;
}

Note *Fret::getNote() const{
    return m_note;
}

int Fret::getIndexString() const{
    return m_indexString;
}
