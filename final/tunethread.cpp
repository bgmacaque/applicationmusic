#include "tunethread.h"
#include <iostream>
TuneThread::TuneThread(Analyze *p_analyze, GraphicTuner *p_tuner){
    m_tune = false;
    m_analyze = p_analyze;
    m_diff = 0;
    m_note = new Note();
    m_tuner = p_tuner;
}

void TuneThread::run(){
    m_tune = true;
    //Starting the record
    m_analyze->start();
    int pos(0);
    for(;;){
        m_analyze->mainNote(m_note, &m_diff);
        if(m_diff < 0){
            pos = -1;
        }else if(m_diff > 0){
            pos = 1;
        }else{
            pos = 0;
        }
        std::cout << m_diff << std::endl;
        m_tuner->setTo(QString::fromStdString(m_note->getName()), pos);
        this->msleep(1000);
    }
}
