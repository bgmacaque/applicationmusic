#include "chord.h"

Chord::Chord(std::vector<Note*> notes, float duration, float volume){
    this->m_notes = notes;
    this->m_volume = volume;
    this->m_duration = duration;
}

Chord::Chord(){
//    this->m_notes
    m_volume   = 0;
    m_duration = 0;
}

//Getter of the duration
double Chord::getDuration() const{
    return this->m_duration;
}
//Setter of the duration
void Chord::setDuration(double duration){
    this->m_duration = duration;
}

//Getter of the volume
double Chord::getVolume() const{
    return this->m_volume;
}
//Setter of the volume
void Chord::setVolume(double volume){
    this->m_volume = volume;
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

//Return  a string of a saved chord
std::string Chord::save(){
    std::string retour = "";
    unsigned int i;
    retour.append("{");
    for(i = 0; i < m_notes.size() ; i++){
        retour += m_notes.at(i)->save();
        if(i != m_notes.size() - 1){
            retour.append(",");
        }
    }
    retour.append("}");
    return retour;
}

void Chord::addNote(Note *n){
    m_notes.push_back(n);
}
