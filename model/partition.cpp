#include "partition.h"

Partition::Partition(){

}

std::vector<Chord> Partition::getChords() const{
    return this->m_chords;
}

void Partition::addChord(Chord chord){
    this->m_chords.push_back(chord);
}

void Partition::play(){

}

void Partition::save(char *path){
    std::ofstream config(path, std::ios::out | std::ios::trunc);

    if(config){

    }
}

Partition Partition::load(){

}

std::string Partition::getDisplay(){
    unsigned int i;
    std::string retour("");
    for(i=0 ; i < m_chords.size() ; i++){
        retour.append(m_chords.at(i).getDisplay());
        retour.append("\n");
    }
    return retour;
}

