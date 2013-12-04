#ifndef PARTITION_H
#define PARTITION_H
#include "chord.h"
#include <vector>
/*

   This class represent a partition

*/
class Partition{

private:
    //Chords that are in the partition
    std::vector<Chord> m_chords;

public:
    //Constructor that initialize an empty partition
    Partition();
    //Getter of the chords
    std::vector<Chord> getChords() const;
    //Function that add a Chord at the end of the Partition
    void addChord(Chord chord);
};

#endif // PARTITION_H
