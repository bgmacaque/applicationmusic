#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include "partition.h"
#include <vector>

/*!
 * \class Analyze analyze.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class can analyze notes and frequencies
 */
class Analyze{
private:
    std::vector<Note> notes;

public:
    Analyze();
    /*!
     * \brief Give the main note of what is recorded by the microphone
     */
    void mainNote(FMOD::Channel *channel);

    /*!
     * \brief Give the note that correspond to the frequency
     */
    Note getNote(int frequency);

    /*!
     * \brief Sort the table places with the values in spectrum
     */
    void sort(int places[], float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Method used in sort
     */
    int place(float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Record a partition
     */
    void record(Partition tab);
};

#endif // ANALYZE_H
