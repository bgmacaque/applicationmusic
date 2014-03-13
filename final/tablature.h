#ifndef TABLATURE_H
#define TABLATURE_H
#include <vector>
#include "frettedchord.h"
#include "partition.h"

class Tablature{
private:
    std::vector<FrettedChord*> m_frets;

public:
    Tablature();
    void toTab(Partition *p);
    std::vector<FrettedChord*> getFrets() const;
};

#endif // TABLATURE_H
