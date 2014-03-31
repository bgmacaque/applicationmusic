#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include <vector>
#include <iostream>
#include "notes.h"
#include "chord.h"

/*!
 * \class Analyze analyze.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class can analyze notes and frequencies
 */
class Analyze{

private:
    FMOD::System *m_system;
    FMOD::Sound *m_sound;
    FMOD::Channel *m_channel;
    int *placesForSpectrum();

    /*!
     * \brief sort Sort the spectrum
     */
    void sort(int places[], float spectrum[], int inf, int sup);

    /*!
     * \brief Method used in sort
     */
    int place(int places[], const float spectrum[], int inf, int sup);

public:
    Analyze(FMOD::System *p_system, FMOD::Sound *p_sound);
    ~Analyze();

    /*!
     * \brief Give the main note of what is recorded by the microphone
     */
    void mainNote(Note *note, float *diff);

    /*!
     * \brief Give the main Chord of the microphone
     */
    Chord *mainChord(int size_max, float freqMin, float freqMax, float *maxVolume);

    /*!
     * \brief Give the main Chord
     */
    Chord *mainChord(int size_max, float *maxVolume);

    /*!
     * \brief Method used to init the FMOD
     */
    void start();

    /*!
     * \brief Methode used to close the channel
     */
    void close();

    /*!
     * \brief Give the note that correspond to the frequency with the difference
     */
    Note *getNote(float frequency, float *diff);

    /*!
     *  \brief Give the note that correspond to the frequency
     */
    Note *getNote(float frequency);

    /*!
     * \brief Method used to get the frequency at a place in the spectrum
     */
    float getFrequency(int placeInSpectrum);

};

#endif // ANALYZE_H
