#include "partition.h"

Partition::Partition(){
    m_tempo = 0;
}

Partition::Partition(int p_tempo){
    m_tempo = p_tempo;
}

std::vector<Chord*> Partition::getChords() const{
    return m_chords;
}

void Partition::addChord(Chord *chord){
    this->m_chords.push_back(chord);
}

void Partition::play(){

}

void Partition::save(const char *path){
    std::ofstream config(path, std::ios::out | std::ios::trunc);
    unsigned int i;
    if(config){
        //Opening the partition
        config << "{" << std::endl;
        //Opening the chords
        config << "\t\"Chords\" : " << std::endl << "\t{" << std::endl;
        for(i = 0; i < m_chords.size() ; i++){
            config << m_chords.at(i)->save();
            if(i != m_chords.size() - 1){
                config << ",";
            }
            config << std::endl;
        }
        //Closing the chords
        config << "\t}" << std::endl;
        config << "}" << std::endl;
    }
}

Partition Partition::load(){

}

std::string Partition::getDisplay(){
    unsigned int i;
    std::string retour("");
    for(i=0 ; i < m_chords.size() ; i++){
        retour.append(m_chords.at(i)->getDisplay());
        retour.append("\n");
    }
    return retour;
}

