#include "note.h"

Note::Note(std::string name, int frequency){
    this->m_name = name;
    this->m_frequency = frequency;
}

int Note::getFrequency() const{
    return this->m_frequency;
}

void Note::setFrequency(int frequency){
    this->m_frequency = frequency;
}

std::string Note::getName() const{
    return this->m_name;
}

void Note::setName(std::string name){
    this->m_name = name;
}

void Note::play(double volume){

}
