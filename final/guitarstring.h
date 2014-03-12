#ifndef GUITARSTRING_H
#define GUITARSTRING_H
#include "analyze.h"

class GuitarString{


private:
    float m_lowFrequency;
    float m_highFrequency;
    std::string m_name;

public:
    GuitarString(std::string p_name, float p_lowFrequency, float p_highFrequency);
    ~GuitarString();

    bool playable(Note *n) const;
};

#endif // GUITARSTRING_H
