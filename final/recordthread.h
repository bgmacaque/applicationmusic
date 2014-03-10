#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QThread>
#include "partition.h"
#include <iostream>

class RecordThread : public QThread
{
private:
    Partition *m_partition;
    Analyze *m_analyze;
    void run();
    bool record;


public:
    Partition *stop();
    RecordThread(Partition *p_partition, Analyze *p_analyze);
};

#endif // RECORDTHREAD_H
