#ifndef TABLATURE_H
#define TABLATURE_H
#include <vector>
#include "frettedchord.h"
#include "partition.h"

/*!
 * \class Tablature tablature.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is a thread that allow the recording to be
 * \brief Done in parallel with the main thread
 * \brief The attribut *m_partition is the partition the thread is recording for
 * \brief The attribut *m_analyze is the Analyze instance needed for the analyze of the partition
 * \brief The attribut record stand for the actual statement of the recording
 */\

class Tablature{
private:
    std::vector<FrettedChord*> m_frets;

public:
    Tablature();
    void toTab(Partition *p);
    std::vector<FrettedChord*> getFrets() const;
};

#endif // TABLATURE_H
