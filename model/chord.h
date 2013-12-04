#ifndef CHORD_H
#define CHORD_H
#include <vector>
#include "note.h"

/*

  This class represent a Chord
  It's 1 to 6 notes played at the same time

*/
class Chord{

private:

    //The duration in time of the chord
    double m_duration;
    //The volume of the chord
    double m_volume;
    //The notes of the chord
    std::vector<Note> m_notes;

public:
    //Constructor of a chord
    Chord(std::vector<Note> notes, double duration, double volume);

    //Getter of the duration
    double getDuration() const;
    //Setter of the duration
    void setDuration(double duration);

    //Getter of the volume
    double getVolume() const;
    //Setter of the volume
    void setVolume(double volume);

    //Methode permettant de jouer des notes
    void play();

};

#endif // CHORD_H
