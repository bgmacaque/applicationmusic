#ifndef CHORD_H
#define CHORD_H
#include <vector>
#include <string>
#include <stdlib.h>
#include "note.h"
#include "notes.h"
#include <iostream>
#include "filereader.h"

/*!
 * \class Chord chord.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represent a chord, of 1 to 6 notes
 */
class Chord{

private:

    /*!
     * \brief The duration in time of the chord
     */
    float m_duration;
    /*!
     * \brief The volume of the chord
     */
    float m_volume;

protected:
    /*!
     * \brief The notes of the chord
     */
    std::vector<Note*> m_notes;

public:
    /*!
     * \brief The constructors of a chord
     */
    Chord(std::vector<Note*> p_notes, float p_duration, float p_volume);
    Chord();
    Chord(float p_duration, float p_volume);

    /*!
     * \brief Getter of the duration
     */
    double getDuration() const;

    /*!
     * \brief Setter of the duration
     */

    void setDuration(float duration);

    /*!
     * \brief Getter of the volume
     */
    double getVolume() const;

    /*!
     * \brief Setter of the volume
     */
    void setVolume(float volume);

    /*!
     * \brief Add p_duration to the current chord duration
     */
    void addDuration(float p_duration);

    /*!
     * \brief Method to play the chord with FMOD
     */
    void play(FMOD::System *p_system, FMOD::Sound *p_sound);

    /*!
     * \brief Add a note to the current chord
     */
    void addNote(Note *n);

    /*!
     * \brief Return true if the note in paramters is in this chord
     */
    bool contains(Note *n);

    /*!
     * \brief The number of notes in the Chord
     */
    int notesNumber() const;

    /*!
     * \brief Getter for the vector composed by all the notes in the chord
     */
    std::vector<Note*> getNotes() const;

    std::string getDisplay();

    QString stringify();

    /*!
     * \brief Return true if the chord contains the same notes
     */
    bool equals(Chord *c);

    /*!
     * \brief Return true if the chord contains no notes
     */
    bool isEmpty();

    static Chord *parse(FileReader *fr);

};

#endif // CHORD_H
