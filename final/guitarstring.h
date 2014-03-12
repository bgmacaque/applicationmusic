#ifndef GUITARSTRING_H
#define GUITARSTRING_H
#include "fret.h"
#include "notes.h"
#include <vector>

class GuitarString{


private:
    float m_lowFrequency;
    float m_highFrequency;
    std::string m_name;
    Fret **m_frets;
    int m_nbFrets;

public:
    GuitarString(std::string p_name, std::string p_noteName, int p_nbFrets);
    ~GuitarString();

    bool playable(Note *n) const;
};

#endif // GUITARSTRING_H
