#include "chord.h"

Chord::Chord(std::vector<Note> notes, double duration, double volume){
    this->m_notes = notes;
    this->m_volume = volume;
    this->m_duration = duration;
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
void Chord::play(){
    unsigned int i;
    for(i = 0 ; i < m_notes.size() ; i++){
        m_notes[i].play(m_volume);
    }
}
