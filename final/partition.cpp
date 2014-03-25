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


void Partition::setTempo(int tempo){
    m_tempo = tempo;
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
    retour.append("{ ");
    retour.append(" \" name \" : \" ");
    retour.append(QString::fromStdString(m_name));
    retour.append(" \" , ");
    retour.append(" \" tempo \" : \" ");
    retour.append(QString::number(m_tempo));
    retour.append(" \" , ");
    retour.append(" \" chords \" : [ ");
    unsigned int i;
    for(i = 0; i < m_chords.size() ; i++){
        retour.append(m_chords.at(i)->stringify());
        if(i != m_chords.size() - 1){
            retour.append(" , ");
        }
    }
    retour.append(" ] ");
    retour.append(" } ");
    return retour;
}

void Partition::save(string path){
    std::ofstream file(path.c_str(), std::ios::out | std::ios::trunc);

    if(file.is_open()){
        //Opening the partition
        file << this->stringify().toStdString();
        file.close();
    }
}

Partition *Partition::load(const char *path){
    Partition *p = new Partition();
    FileReader *fr = new FileReader(path);
    std::string word;
    word = fr->next();
    if(word.compare("{") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("name") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(fr->isNotJsonString(word)){
        //Here we have the name
        p->m_name = word;
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(",") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("tempo") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(fr->isNotJsonString(word)){
        p->m_tempo = atoi(word.c_str());
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(",") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("chords") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("[") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("{") == 0){
        bool hasNextChord = true;
        while(hasNextChord){
            p->addChord(Chord::parse(fr));
            word = fr->next();
            if(word.compare("]") == 0){
                hasNextChord = false;
            }else if(word.compare(",") != 0){
                cout << "CACA" << endl;
                throw "Parse error";
            }else{
                word = fr->next();
            }
        }
    }else if(word.compare("]") != 0){
        throw "Parse error";
    }
    if(fr->getCurrent().compare("]") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("}") != 0){
        throw "Parse error";
    }

    cout << p->stringify().toStdString() << endl;
    delete fr;
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

