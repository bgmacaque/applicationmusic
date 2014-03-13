#include "fret.h"
#include <iostream>

Fret::Fret(int p_number, Note *p_note){
    m_number = p_number;
    m_note = p_note;
    std::cout << m_note->getFrequency() << std::endl;
}

int Fret::getNumber() const{
    return m_number;
}

Note *Fret::getNote() const{
    return m_note;
}
