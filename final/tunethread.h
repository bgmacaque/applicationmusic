#ifndef TUNETHREAD_H
#define TUNETHREAD_H
#include "analyze.h"
#include <QThread>
#include "graphictuner.h"
/*!
 * \class TuneThread tunethread.h
 * \author Valentin STERN, Vincent ALBERT, Adonis NAJIMI, Theo GERRIET
 * \brief The thread of the tuner
 */
class TuneThread : public QThread
{
private:
    Analyze *m_analyze;
    bool m_tune;
    Note *m_note;
    float m_diff;
    GraphicTuner *m_tuner;
    void run();
public:
    TuneThread(Analyze *p_analyze, GraphicTuner *p_tuner);

};

#endif // TUNETHREAD_H
