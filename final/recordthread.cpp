#include "recordthread.h"
#include <ctime>
//Just for debug, removed after
using namespace std;


RecordThread::RecordThread(Partition *p_partition, Analyze *p_analyze){
    m_partition = p_partition;
    m_analyze = p_analyze;
    record = false;
}

void RecordThread::run(){
    record = true;
    //Starting the record
    m_analyze->start();
    Chord *c = 0;
    Chord *prec = 0;
    float maxVolume;
    double step = m_partition->getTempo() / 16;
    Guitar *g = Guitar::get_instance();
    while(record){
        //Get the main chord with the possible frenquencies of the instrument
        c = m_analyze->mainChord(6, g->getLowestFrequency(), g->getHighestFrequency(), &maxVolume);
        c->setVolume(maxVolume);
        //If we have found a chord
        if(prec != 0){
            //If it isn't the same as before, we add it
//            cout << maxVolume << endl;
            if(!prec->equals(c) && !c->isEmpty()){
                //If the volume is lower than the highstep
                if(maxVolume < m_partition->getHighStep()){
                    //We add some duration
                    m_partition->addDurationLastChord(step);
                }else{
                    //If the volume is higher than the highstep
                    c->setDuration(m_partition->getTempo() / 16);
                    m_partition->addChord(c);
                }
            }else{
                //We have to add some duration to the previous chord
                if(!c->isEmpty()){
                    m_partition->addDurationLastChord(step);
                }else{
//                    if(prec->isEmpty()){
//                        m_partition->addDurationLastChord(m_partition->getTempo() / 16);
//                    }else{
//                        c->setDuration(m_partition->getTempo() / 16);
//                        m_partition->addChord(c);
//                    }
                }
            }
        }
        prec = c;
        //Sleeping for the shortest time in music theory(1 min / bpm / 16)
        this->msleep( 60 * 1000 / m_partition->getTempo() / 16);
//        std::cout << "RECORDING" << std::endl;
    }
}

Partition *RecordThread::stop(){
    record = false;
    this->quit();
    m_analyze->close();
    return m_partition;
}
