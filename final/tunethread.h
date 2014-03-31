#ifndef TUNETHREAD_H
#define TUNETHREAD_H
#include "analyze.h"
#include <QThread>
#include "graphictuner.h"

class TuneThread : public QThread
{
private:
    Analyze *m_analyze;
    bool m_tune;
    Note *m_note;
    float m_diff;
    GraphicTuner *m_tuner;
public:
    TuneThread(Analyze *p_analyze, GraphicTuner *p_tuner);
    void run();
};

#endif // TUNETHREAD_H
