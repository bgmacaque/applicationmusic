#ifndef NOTE_H
#define NOTE_H
#include <string>

/*

    This class represent a note

*/
class Note{

private:
    //Frequency of the note
    int m_frequency;
    //Name of the note in the english norm (A, B ..)
    std::string m_name;

public:
    //Note constructor
    Note(std::string name, int frequency);

    //Setter of name
    void setName(std::string name);
    //Getter of name
    std::string getName() const;

    //Setter of frequency
    void setFrequency(int frequency);
    //Getter of frequency
    int getFrequency() const;
};

#endif // NOTE_H
