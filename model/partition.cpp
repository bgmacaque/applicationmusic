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
    std::ofstream file(path, std::ios::out | std::ios::trunc);
    unsigned int i;
    if(file.is_open()){
        //Opening the partition
        file << "{" << std::endl;
        //Opening the chords
        file << "\t\"Chords\" : " << std::endl << "\t{" << std::endl;
        for(i = 0; i < m_chords.size() ; i++){
            file << m_chords.at(i)->save();
            if(i != m_chords.size() - 1){
                file << ",";
            }
            file << std::endl;
        }
        //Closing the chords
        file << "\t}" << std::endl;
        file << "}" << std::endl;
        file.close();
    }
}

Partition *Partition::load(const char *path){
    Partition *p = new Partition();
    std::ifstream file(path, std::ios::in);
    std::string line;
    unsigned int level(0);
    if(file.is_open()){

        while(std::getline(file, line)){
//            std::cout << line << std::endl;
            if(line.compare("{")){
                level++;
            }

            if(1){
                level = level - 1;
            }
//            std::cout << level << std::endl;
        }
        if(level != 0){
//            std::cout << "JSON parse error" << std::endl;
        }
        file.close();
    }
    return p;
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

