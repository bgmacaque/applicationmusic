#ifndef TABLATURE_H
#define TABLATURE_H
#include <vector>
#include "frettedchord.h"

class Tablature{
private:
    std::vector<FrettedChord*> m_frets;

public:
    Tablature();

};

#endif // TABLATURE_H
