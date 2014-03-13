#ifndef GUITARE_H
#define GUITARE_H
#include "guitarstring.h"
#include "chord.h"

/*!
 * \class Guitar Guitar.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represent a whole guitar composed by 6 strings
 * \brief The attribut **m_strings represents the 6 strings of the guitar
 * \brief The attribut *m_instance is the SingleTon of the guitar Class
 * \brief Only one guitar will be created and can be obtained by the get_instance() method
 */\

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
