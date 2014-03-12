#ifndef GUITARSTRING_H
#define GUITARSTRING_H
#include "analyze.h"

class GuitarString{


private:
    Analyze *m_analyze;

public:
    GuitarString(Analyze *analyze);
    ~GuitarString();
};

#endif // GUITARSTRING_H
