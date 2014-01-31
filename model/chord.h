#ifndef CHORD_H
#define CHORD_H
#include <vector>
#include <string>
#include "note.h"

/*!
 * \class Chord chord.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represent a chord, of 1 to 6 notes
 */
class Chord{

private:

    //The duration in time of the chord
    float m_duration;
    //The volume of the chord
    float m_volume;
    //The notes of the chord
    std::vector<Note> m_notes;

public:
    //Constructor of a chord
    Chord(std::vector<Note> notes, float duration, float volume);

    //Getter of the duration
    double getDuration() const;
    //Setter of the duration
    void setDuration(double duration);

    //Getter of the volume
    double getVolume() const;
    //Setter of the volume
    void setVolume(double volume);

    //Method which allows to play notes 
    void play(FMOD::System *p_system, FMOD::Sound *p_sound);

    //Method used to display the chord(Debug)
    std::string getDisplay();

};

#endif // CHORD_H
