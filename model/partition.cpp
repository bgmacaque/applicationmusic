#include "partition.h"

Partition::Partition(){

}

std::vector<Chord> Partition::getChords() const{
    return this->m_chords;
}

void Partition::addChord(Chord chord){
    this->m_chords.push_back(chord);
}

