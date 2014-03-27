#ifndef PARTITION_H
#define PARTITION_H
#include "chord.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "analyze.h"
#include <QObject>
#include <QString>
#include "filereader.h"


/*!
 * \class Partition partition.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class that represent a partition
 * \brief The attribut m_tempo represents the tempo of this partition
 * \brief The attribut m_chords is a vector of chords that are meaned to be played
 */
class Partition : public QObject{

private:
    //Chords that are in the partition
    std::vector<Chord*> m_chords;

    int m_tempo;

    std::string m_name;

    float m_lowStep;

    float m_highStep;

public:
    //Constructor that initialize an empty partition
    Partition();
    Partition(int tempo, float p_lowStep, float p_highStep);

    //Display the partition in text format (debug)
    std::string getDisplay();

    //Getter of the chords
    std::vector<Chord*> getChords() const;

    //Method that add a Chord at the end of the Partition
    void addChord(Chord *chord);

    //Method that play all the partition
    void startPlay();

    void stopPlay();

    void save(std::string path);

    float getHighStep() const;

    QString stringify();

    std::string getName();

    void setName(std::string p_name);

    void addDurationLastChord(double p_duration);

    int getTempo();

    void deleteChords();

    void setTempo(int tempo);

    static Partition* load(const char *path);

};

#endif // PARTITION_H
