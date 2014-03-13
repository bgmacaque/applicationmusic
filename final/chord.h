#ifndef CHORD_H
#define CHORD_H
#include <vector>
#include <string>
#include "note.h"
#include <iostream>

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

protected:
    //The notes of the chord
    std::vector<Note*> m_notes;

public:
    //Constructor of a chord
    Chord(std::vector<Note*> p_notes, float p_duration, float p_volume);
    Chord();
    Chord(float p_duration, float p_volume);

    //Getter of the duration
    double getDuration() const;
    //Setter of the duration
    void setDuration(float duration);

    //Getter of the volume
    double getVolume() const;
    //Setter of the volume
    void setVolume(float volume);

    void addDuration(float p_duration);

    //Method which allows to play notes 
    void play(FMOD::System *p_system, FMOD::Sound *p_sound);

    void addNote(Note *n);

    //Method return true if the chord contains the note
    bool contains(Note *n);

    int notesNumber() const;

    std::vector<Note*> getNotes() const;

    //Method used to display the chord(Debug)
    std::string getDisplay();

    std::string save();

    bool equals(Chord *c);

    bool isEmpty();

};

#endif // CHORD_H
