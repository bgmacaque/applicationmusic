#include "tablature.h"

Tablature::Tablature(){
}

void Tablature::toTab(Partition *p){
    std::vector<Chord *> chords = p->getChords();
    Chord *chord;
    int i(0);
    Guitar *g = Guitar::get_instance();
    for(i = 0 ; i < chords.size() ; i++){
        chord = chords.at(i);
        m_frets.push_back(new FrettedChord(chord));
    }
}
