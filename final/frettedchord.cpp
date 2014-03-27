#include "frettedchord.h"

FrettedChord::FrettedChord(Chord *c){
    Guitar *g = Guitar::get_instance();
    m_frets = g->getFrets(c, &m_numberFrets);
    m_chord = c;
}

Fret **FrettedChord::getFrets(){
    return m_frets;
}

int FrettedChord::getNumberFrets(){
    return m_numberFrets;
}

float FrettedChord::getDuration(){
    return m_chord->getDuration();
}
