#ifndef GUITARE_H
#define GUITARE_H
#include "guitarstring.h"
#include "chord.h"
class Guitar{

private:
    GuitarString **m_strings;
    Guitar();
    ~Guitar();
    static Guitar *m_instance;
    int m_nbStrings;

public:
    static Guitar *get_instance();
    static void kill();
    Fret **getFrets(Chord *c) const;
};

#endif // GUITARE_H
