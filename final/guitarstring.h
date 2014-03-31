#ifndef GUITARSTRING_H
#define GUITARSTRING_H
#include "fret.h"
#include "notes.h"
#include <vector>

/*!
 * \class GuitarString guitarstring.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represent a single string of the guitar
 * \brief The attribut m_lowFrequency is the minimum frequency on this string
 * \brief The attribut m_highFrequency is the maximum frequency on this string
 * \brief The attribut m_name is for convenient purpose,
 * \brief The user is free to rename the String to his convenience
 */\

class GuitarString{


private:
    float m_lowFrequency;
    float m_highFrequency;
    std::string m_name;
    Fret **m_frets;
    int m_nbFrets;
    int m_number;

public:
    GuitarString(std::string p_name, std::string p_noteName, int p_nbFrets, int p_number);
    GuitarString();
    ~GuitarString();

    /*!
     * \brief Get the fret for a note on the string
     */
    Fret *getFret(Note *n) const;

    /*!
     * \brief Show if the note is playable on the string or not
     */
    bool playable(Note *n) const;

    /*!
     * \brief Get the lowest frequency on the string
     */
    float getLowFrequency();

    /*!
     * \brief Get the highest frequency on the string
     */
    float getHighFrequency();
};

#endif // GUITARSTRING_H
