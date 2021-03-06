#include "chord.h"

//Just during debug
using namespace std;


Chord::Chord(std::vector<Note*> p_notes, float p_duration, float p_volume){
    m_notes = p_notes;
    m_volume = p_volume;
    m_duration = p_duration;
}


void Chord::sort(){
    Note **notes = new Note*[m_notes.size()];
    unsigned int i(0);
    unsigned int taille = m_notes.size();
    for(i = 0 ; i < taille ; i++){
        notes[i] = m_notes.at(i);
    }
    while(!m_notes.empty()){
        m_notes.pop_back();
    }
    bool sorted = false;
    int tailleTemp = taille;
    Note *temp;
    while(!sorted){
        sorted = true;
        for(i = 0 ; i < tailleTemp - 1; i++){
            if(notes[i]->getFrequency() > notes[i + 1]->getFrequency()){
                temp = notes[i];
                notes[i] = notes[i + 1];
                notes[i + 1] = temp;
                sorted = false;
            }
        }
        tailleTemp--;
    }


    for(i = 0 ; i < taille ; i++){
        m_notes.push_back(notes[i]);
    }
}

Chord::Chord(){
    m_volume = 0;
    m_duration = 0;
}

Chord::Chord(float p_duration, float p_volume){
    m_volume = p_volume;
    m_duration = p_duration;
}

bool Chord::isEmpty(){
    return m_notes.size() == 0;
}

void Chord::addDuration(float p_duration){
    m_duration += p_duration;
}

std::vector<Note*> Chord::getNotes() const{
    return m_notes;
}

//Getter of the duration
double Chord::getDuration() const{
    return this->m_duration;
}
//Setter of the duration
void Chord::setDuration(float duration){
    this->m_duration = duration;
}

//Getter of the volume
double Chord::getVolume() const{
    return this->m_volume;
}
//Setter of the volume
void Chord::setVolume(float volume){
    this->m_volume = volume;
}

int Chord::notesNumber() const{
    return m_notes.size();
}

//Play every notes in the chord
void Chord::play(FMOD::System *p_system, FMOD::Sound *p_sound){
    unsigned int i;
    for(i = 0 ; i < m_notes.size() ; i++){
        m_notes.at(i)->play(m_volume, m_duration, p_system, p_sound);
    }
}

//Display a chord (for debug)
std::string Chord::getDisplay(){
    std::string retour("[");
    unsigned int i;
    for(i = 0; i < m_notes.size(); i++){
        retour.append(m_notes.at(i)->getDisplay());
        if(i != m_notes.size() - 1){
            retour.append(",");
        }
    }
    retour.append("]");
    return retour;
}

bool Chord::equals(Chord *c){
    bool retour = true;
    unsigned int i(0);
    if(c->m_notes.size() != m_notes.size()){
        retour = false;
    }else{
        //Checking every notes
        for(i = 0 ; i < m_notes.size() ; i++){
            retour = retour && (this->contains(c->m_notes.at(i)));
        }
    }
    return retour;
}

//Return  a string of a saved chord
QString Chord::stringify(){
    QString retour = "";
    QString volume = " \" volume \" : ";
    QString duration = " \" duration \" : ";
    unsigned int i;


    if(!m_volume){
        volume.append(" 0 ");
    }else{
        volume.append(QString::number(m_volume));
    }
    volume.append(" , ");
    if(!m_duration){
        duration.append(" 0 ");
    }else{
        duration.append(QString::number(m_duration));
    }
    duration.append(" , ");
    retour.append(" { ");
    retour.append(volume);
    retour.append(duration);
    retour.append(" \" notes \" : ");
    retour.append(" [ ");
    for(i = 0; i < m_notes.size() ; i++){
        retour.append(m_notes.at(i)->stringify());
        if(i != m_notes.size() - 1){
            retour.append(" , ");
        }
    }
    retour.append(" ] ");
    retour.append(" } ");
    return retour;
}

bool Chord::contains(Note *n){
    bool retour = false;
    unsigned int i(0);
    while(i < m_notes.size() && !retour){
        if(*m_notes.at(i) == *n){
            retour = true;
        }
        i++;
    }
    return retour;
}

void Chord::addNote(Note *n){
    m_notes.push_back(n);
}


Chord *Chord::parse(FileReader *fr){
    Chord *retour = new Chord();
    if(fr->getCurrent().compare("{") != 0){
        throw "Parse error";
    }
    std::string word;
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("volume") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0 ){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
//    word = fr->next();
//    if(word.compare("\"") != 0){
//        throw "Parse error";
//    }
    word = fr->next();
    if(fr->isNotJsonString(word)){
        retour->setVolume(atof(word.c_str()));
    }else{
        throw "Parse error";
    }

//    word = fr->next();
//    if(word.compare("\"") != 0){
//        throw "Parse error";
//    }
    word = fr->next();
    if(word.compare(",") != 0){
        throw "Parse error";
    }

    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("duration") != 0){
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
//    word = fr->next();
//    if(word.compare("\"") != 0){
//        throw "Parse error";
//    }
    word = fr->next();
    if(fr->isNotJsonString(word)){
        retour->setDuration(::atof(word.c_str()));
    }else{
        throw "Parse error";
    }
//    word = fr->next();
//    if(word.compare("\"") != 0){
//        throw "Parse error";
//    }
    word = fr->next();
    if(word.compare(",") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("notes") != 0){
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
    if(word.compare("\"") == 0){
        bool hasNextNote = true;
        while(hasNextNote){
            if(word.compare("\"") != 0){
                throw "Parse error";
            }
            word = fr->next();
            if(fr->isNotJsonString(word)){
                //WE HAVE TO VERIFY HERE IF IT'S A NOTE
                Notes *notes = Notes::get_instance();
                retour->addNote(notes->searchNote(word));
            }else{
                throw "Parse error";
            }
            word = fr->next();
            if(word.compare("\"") != 0){
                throw "Parse error";
            }
            word = fr->next();
            if(word.compare(",") != 0){
                if(word.compare("]") != 0){
                    throw "Parse error";
                }else{
                    hasNextNote = false;
                }
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
    word  = fr->next();
    if(word.compare("}") != 0){
        throw "Parse error";
    }
    return retour;
}
