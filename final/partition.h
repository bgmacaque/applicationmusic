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
//#include "tablature.h"


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

    std::string m_path;

public:
    Partition();
    Partition(int tempo, float p_lowStep, float p_highStep);

    /*!
     * \brief Display in text format
     */
    std::string getDisplay();

    /*!
     * \brief Get the path of the partition
     */
    std::string getPath() const;

    /*!
     * \brief Set the path of the partition
     */
    void setPath(std::string p_path);

    /*!
     * \brief Get all the chords of the partition
     */
    std::vector<Chord*> getChords() const;

    /*!
     * \brief Add a chord at the end of the partition
     */
    void addChord(Chord *chord);

    /*!
     * \brief Save a partition at the path specified
     */
    void save(std::string path);

    /*!
     * \brief Get the highstep of the partition
     */
    float getHighStep() const;

    /*!
     * \brief Return the string description of the partition in JSON
     */
    QString stringify();

    /*!
     * \brief Parse the JSON string into an object
     */
    static Partition *parse(std::string json);

    /*!
     * \brief Get the name of the partition
     */
    std::string getName();

    /*!
     * \brief Set the name of the partition
     */
    void setName(std::string p_name);

    /*!
     * \brief Add duration to the last chord
     */
    void addDurationLastChord(double p_duration);

    /*!
     * \brief Get tempo of the partition
     */
    int getTempo();

    /*!
     * \brief Delete all the chords of the parititon
     */
    void deleteChords();

    /*!
     * \brief Set the tempo of the partition
     */
    void setTempo(int tempo);

    /*!
     * \brief Load a partition with the path specified
     */
    static Partition *load(const char *path);

};

#endif // PARTITION_H
