<<<<<<< HEAD
#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include "partition.h"
#include <vector>

/*!
 * \class Analyze analyze.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class can analyze notes and frequencies
 */
class Analyze{

private:
    Note **notes;

public:
    Analyze();
    ~Analyze();

    /*!
     * \brief Give the main note of what is recorded by the microphone
     */
    void mainNote(FMOD::System *p_system, FMOD::Sound *p_sound, int *diff);

    /*!
     * \brief Give the note that correspond to the frequency
     */
    Note *getNote(float frequency, int *diff);

    /*!
     * \brief Sort the table places with the values in spectrum
     */
    void sort(int places[], float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Method used in sort
     */
    int place(float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Record a partition
     */
    void record(Partition tab);
};

#endif // ANALYZE_H
=======
#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include "partition.h"
#include <vector>

/*!
 * \class Analyze analyze.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class can analyze notes and frequencies
 */
class Analyze{

private:
    Note **m_notes;
    FMOD::System *m_system;
    FMOD::Sound *m_sound;
    FMOD::Channel *m_channel;

public:
    Analyze();
    ~Analyze();

    /*!
     * \brief Give the main note of what is recorded by the microphone
     */
    void mainNote(int *diff);

    /*!
     * \brief Method used to init the FMOD
     */
    void init(FMOD::System *p_system, FMOD::Sound *p_sound);

    /*!
     * \brief Give the note that correspond to the frequency
     */
    Note *getNote(float frequency, int *diff);

    /*!
     * \brief Sort the table places with the values in spectrum
     */
    void sort(int places[], float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Method used in sort
     */
    int place(float spectrum[], int size, int inf, int sup);

    /*!
     * \brief Record a partition
     */
    void record(Partition tab);
};

#endif // ANALYZE_H
>>>>>>> Changes in Analyze, for graphical use
