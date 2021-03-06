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

float Note::getFrequency() const{
    return m_frequency;
}

/* @void set the frenquency to the 'frequency' value*/
void Note::setFrequency(float frequency){
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
    //Load the file with the name
    //Play the sound
    p_system->playSound(FMOD_CHANNEL_REUSE, p_sound, 0, &channel);
    //Set the volume
    channel->setVolume(volume);
    //Playing during the whole duration
    usleep(duration);
    //Stop playing
    channel->stop();
}


std::string Note::getDisplay(){
    if(m_name == ""){
        return "Not in range";
    }else{
        return m_name;
    }
}

bool Note::equals(const Note &n) const{
    bool retour = true;
    retour = retour && (m_name.compare(n.m_name) == 0);
    retour = retour && (m_frequency == n.m_frequency);
    return retour;
}



//Return a string of a saved notes
QString Note::stringify(){
    QString retour = "";
    retour.append(" \" ");
    retour.append(QString::fromStdString(m_name));
    retour.append(" \" ");
    return retour;
}


bool operator==(Note const& n1, Note const& n2){
    return n1.equals(n2);
}

bool operator!=(Note const& n1, Note const& n2){
    return !n1.equals(n2);
}
