#ifndef NOTE_H
#define NOTE_H
#include <string>
#include <fmod.hpp>
#include <unistd.h>
#include <QString>

/*!
 * \class Note note.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class that represents a Note
 * \brief The attribut m_frequency represents the frequency of this note
 * \brief The attribut m_name stand for the note name (ex: #E #A)
 */

class Note{

private:
    //Frequency of the note
    float m_frequency;
    //Name of the note in the english norm (A, B ..)
    std::string m_name;

public:
    //Note constructor
    Note(std::string name, float frequency);
    Note();

    /*!
     * \brief Setter of the name
     */
    void setName(std::string name);

    /*!
     * \brief Getter of the name
     */
    std::string getName() const;


    /*!
     * \brief Setter of the frequency
     */
    void setFrequency(float frequency);

    /*!
     * \brief Getter of the frequency
     */
    float getFrequency() const;

    /*!
     * \brief True if this and n are equals
     */
    bool equals(Note const& n) const;

    /*!
     * \brief Method used to play a note
     */
    void play(float volume, float duration, FMOD::System *p_system, FMOD::Sound *p_sound);

    /*!
     * \brief Return a string representing a note
     */
    std::string getDisplay();

    /*!
     * \brief Return this object in a string form
     */
    QString stringify();

};

bool operator==(Note const& n1, Note const& n2);
bool operator!=(Note const& n1, Note const& n2);

#endif // NOTE_H
