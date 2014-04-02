#include "tablature.h"

Tablature::Tablature(){
}

void Tablature::toTab(Partition *p){
    m_frets.clear();
    std::vector<Chord *> chords = p->getChords();
    Chord *chord;
    int i(0);
    Guitar *g = Guitar::get_instance();
    for(i = 0 ; i < chords.size() ; i++){
        chord = chords.at(i);
        m_frets.push_back(new FrettedChord(chord));
    }
}

std::vector<FrettedChord*> Tablature::getFrets() const{
    return m_frets;
}

void Tablature::parse(FileReader *fr) const{
    std::string word = fr->next();
    if(word.compare("[") != 0){
        throw "Parse error";
    }

    word = fr->next();
    if(word.compare("[") != 0){
        throw "Parse error";
    }

    while(word.compare("[") == 0){

        FrettedChord::parse(fr);
        word = fr->next();
        if(word.compare(",") == 0){
            word = fr->next();
        }
    }
    if(word.compare("]") != 0){
        throw "Parse error";
    }
}

QString Tablature::stringify() const{
    QString retour = "";
    retour.append(" [ ");
    for(unsigned int i = 0 ; i < m_frets.size() ; i++){
        retour.append(m_frets.at(i)->stringify());
        if(i != m_frets.size() - 1){
            retour.append(" , ");
        }
    }
    retour.append(" ] ");
    return retour;
}


Tablature::~Tablature(){
    m_frets.clear();
}
