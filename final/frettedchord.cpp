#include "frettedchord.h"

FrettedChord::FrettedChord(Chord *c){
    Guitar *g = Guitar::get_instance();
    m_frets = g->getFrets(c);
}

Fret **FrettedChord::getFrets(){
    return m_frets;
}
