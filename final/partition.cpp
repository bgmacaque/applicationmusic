#include "partition.h"

//During debug only
using namespace std;

Partition::Partition(){
    m_tempo = 0;
}

Partition::Partition(int p_tempo, float p_lowStep, float p_highStep){
    m_tempo = p_tempo;
    m_lowStep = p_lowStep;
    m_highStep = p_highStep;
}

std::vector<Chord*> Partition::getChords() const{
    return m_chords;
}

void Partition::addChord(Chord *chord){
    this->m_chords.push_back(chord);
}

void Partition::addDurationLastChord(double p_duration){
    if(!m_chords.empty()){
        Chord *c = m_chords.at(m_chords.size() - 1);
        c->addDuration(p_duration);
    }
}

void Partition::setName(std::string p_name){
    m_name = p_name;
}

std::string Partition::getName(){
    return m_name;
}


float Partition::getHighStep() const{
    return m_highStep;
}

int Partition::getTempo(){
    return m_tempo;
}


void Partition::startPlay(){

}

void Partition::stopPlay(){

}

QString Partition::stringify(){
    QString retour = "";
    retour.append("{\n");
    retour.append("\t\"Chords\" : \n\t{\n");
    unsigned int i;
    for(i = 0; i < m_chords.size() ; i++){
        retour.append(m_chords.at(i)->stringify());
        if(i != m_chords.size() - 1){
            retour.append(",");
        }
        retour.append("\n");
    }
    retour.append("\t}\n");
    retour.append("}\n");
    return retour;
}

void Partition::save(string path){
    std::ofstream file(path.c_str(), std::ios::out | std::ios::trunc);

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

