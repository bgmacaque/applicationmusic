#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QThread>
#include "partition.h"
#include <iostream>
#include "graphicscore.h"
#include "frettedchord.h"

/*!
 * \class RecordThread recordthread.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is a thread that allow the recording to be
 * \brief Done in parallel with the main thread
 * \brief The attribut *m_partition is the partition the thread is recording for
 * \brief The attribut *m_analyze is the Analyze instance needed for the analyze of the partition
 * \brief The attribut record stand for the actual statement of the recording
 */\

class RecordThread : public QThread
{
private:
    Partition *m_partition;
    Analyze *m_analyze;
    void run();
    bool record;


public:
    /*!
     * \brief Stop the recording of a partition
     */
    Partition *stop();
    RecordThread(Partition *p_partition, Analyze *p_analyze);
};

#endif // RECORDTHREAD_H
