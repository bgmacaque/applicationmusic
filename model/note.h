#ifndef NOTE_H
#define NOTE_H
#include <string>

/*!
 * \class Note note.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief Class that represent a Note
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

    //Setter of name
    void setName(std::string name);
    //Getter of name
    std::string getName() const;

    //Setter of frequency
    void setFrequency(int frequency);
    //Getter of frequency
    int getFrequency() const;

    //Play the note
    void play(double volume, double duration);

    //Display the note(Debug only)
    std::string getDisplay();
};

#endif // NOTE_H
