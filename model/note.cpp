#include "note.h"

/*
	This class represents the notes that will compose a tab/
	Notes can be grouped to form a Chord.
*/


//*************
// Constructor
//*************

Note::Note(std::string name, float frequency){
    this->m_name = name;
    this->m_frequency = frequency;
}

Note::Note(){
}

//**********
// Methods
//**********

/* @return the frequency of the note*/

int Note::getFrequency() const{
    return this->m_frequency;
}

/* @void set the frenquency to the 'frequency' value*/
void Note::setFrequency(int frequency){
    this->m_frequency = frequency;
}

/* @return the name of the note*/
std::string Note::getName() const{
    return this->m_name;
}

/* @void set the name of the not to the 'name' value*/
void Note::setName(std::string name){
    this->m_name = name;
}

/* @void play a note with a volume value equals to 'volume'*/
void Note::play(double volume, double duration){

}


std::string Note::getDisplay(){
    return this->m_name;
}
