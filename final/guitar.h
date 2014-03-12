#ifndef GUITARE_H
#define GUITARE_H
#include "guitarstring.h".h"
class Guitar{

private:
    GuitarString **strings;
    Guitar();
    ~Guitar();
    static Guitar *m_instance;

public:
    static Guitar *get_instance();
    static void kill();
};

#endif // GUITARE_H
