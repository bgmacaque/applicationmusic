#include "partition.h"

//During debug only
using namespace std;

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

void Partition::setName(std::string p_name){
    m_name = p_name;
}

std::string Partition::getName(){
    return m_name;
}

void Partition::record(Analyze *a, bool *tune){
    int i(0);
    //Starting the record
    a->start();
    Chord *c = 0;
    Chord *prec = 0;
    for(i = 0 ; i < 5000 ; i++){
        c = a->mainChord(6);
        cout << c->getDisplay() << endl;
        //Sleeping for the shortest time (1 min / bpm / 16)
        usleep(1000 * 1000 * 60 / (m_tempo * 16));
    }
    a->close();
}

void Partition::play(){

}

std::string Partition::toJSON(){
    std::string retour = "";
    retour += "{\n";
    retour += "\t\"Chords\" : \n\t{\n";
    unsigned int i;
    for(i = 0; i < m_chords.size() ; i++){
        retour += m_chords.at(i)->save();
        if(i != m_chords.size() - 1){
            retour += ",";
        }
        retour += "\n";
    }
    retour += "\t}\n";
    retour += "}\n";
    return retour;
}

void Partition::save(const char *path){
    std::ofstream file(path, std::ios::out | std::ios::trunc);

    if(file.is_open()){
        //Opening the partition
        file << this->toJSON();
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

