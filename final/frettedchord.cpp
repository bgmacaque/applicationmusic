#include "frettedchord.h"

FrettedChord::FrettedChord(Chord *c){
    Guitar *g = Guitar::get_instance();
    m_frets = g->getFrets(c, &m_numberFrets);
    m_chord = c;
}

Fret **FrettedChord::getFrets() const{
    return m_frets;
}

int FrettedChord::getNumberFrets() const{
    return m_numberFrets;
}

float FrettedChord::getDuration() const{
    return m_chord->getDuration();
}

FrettedChord::~FrettedChord(){
    for(unsigned int i = 0 ; i < m_numberFrets ; i++){
        delete m_frets[i];
    }
    delete[] m_frets;
}
