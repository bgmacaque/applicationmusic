#include "note.h"

/*
	This class represents the notes that will compose a tab/
	Notes can be grouped to form a Chord.
*/


//*************
// Constructor
//*************

Note::Note(std::string name, float frequency){
    m_name = name;
    m_frequency = frequency;
}

Note::Note(){
}

//**********
// Methods
//**********

/* @return the frequency of the note*/

int Note::getFrequency() const{
    return m_frequency;
}

/* @void set the frenquency to the 'frequency' value*/
void Note::setFrequency(int frequency){
    m_frequency = frequency;
}

/* @return the name of the note*/
std::string Note::getName() const{
    return m_name;
}

/* @void set the name of the not to the 'name' value*/
void Note::setName(std::string name){
    m_name = name;
}

/* @void play a note with a volume value equals to 'volume'*/
void Note::play(float volume, float duration, FMOD::System *p_system, FMOD::Sound *p_sound){
    FMOD::Channel *channel = 0;
    //Prendre le fichier
    //Jouer le son
    p_system->playSound(FMOD_CHANNEL_REUSE, p_sound, 0, &channel);
    //Changer le volume
    channel->setVolume(volume);
    //Arrêter de jouer
    usleep(duration);
    channel->stop();
}


std::string Note::getDisplay(){
    if(m_name == ""){
        return "Not in range";
    }else{
        return m_name;
    }
}
