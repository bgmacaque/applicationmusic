#ifndef PARTITION_H
#define PARTITION_H
#include "chord.h"
#include <string>
#include <vector>


/*!
 * \class Partition partition.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief Class that represent a partition
 */
class Partition{

private:
    //Chords that are in the partition
    std::vector<Chord> m_chords;

public:
    //Constructor that initialize an empty partition
    Partition();

    //Display the partition in text format (debug)
    std::string getDisplay();

    //Getter of the chords
    std::vector<Chord> getChords() const;

    //Method that add a Chord at the end of the Partition
    void addChord(Chord chord);

    //Method that play all the partition
    void play();
};

#endif // PARTITION_H
