#include "chord.h"

//Just during debug
using namespace std;


Chord::Chord(std::vector<Note*> p_notes, float p_duration, float p_volume){
    m_notes = p_notes;
    m_volume = p_volume;
    m_duration = p_duration;
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
std::string Chord::save(){
    std::string retour = "";
    std::string volume = "\"volume\" : ";
    std::string duration = "\"duration\" : ";
    unsigned int i;


    if(!m_volume){
        volume += "0";
    }else{
        volume += m_volume;
    }
    volume += ", ";
    if(!m_duration){
        duration += "0";
    }else{
        duration += m_duration;
    }
    duration.append(", ");
    retour.append("{\n");
    retour.append("\t" + volume + "\n");
    retour.append("\t" + duration + "\n");
    retour.append("\t\"notes\" : ");
    retour.append("{");
    for(i = 0; i < m_notes.size() ; i++){
        retour += m_notes.at(i)->save();
        if(i != m_notes.size() - 1){
            retour.append(",");
        }
    }
    retour.append("}\n");
    retour.append("}");
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
