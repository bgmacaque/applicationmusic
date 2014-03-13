#include "recordthread.h"

//Just for debug, removed after
using namespace std;


RecordThread::RecordThread(Partition *p_partition, Analyze *p_analyze){
    m_partition = p_partition;
    m_analyze = p_analyze;
    record = false;
}

void RecordThread::run(){
//    m_partition->startRecord(m_analyze);
    record = true;
    int i(0);
    //Starting the record
    m_analyze->start();
    Chord *c = 0;
    Chord *prec = 0;
    float maxVolume;
    double step = m_partition->getTempo() / 16;
    while(record){
        //Get the main chord with the possible frenquencies of the instrument
        c = m_analyze->mainChord(6, 82.41, 1318.51, &maxVolume);
        c->setVolume(maxVolume);
        //If we have found a chord
        if(prec != 0){
            //If it isn't the same as before, we add it
            cout << maxVolume << endl;
            if(!prec->equals(c) && !c->isEmpty()){
                //If the volume is lower than the highstep
                if(maxVolume < m_partition->getHighStep()){
                    //We add some duration
                    m_partition->addDurationLastChord(step);
                }else{
                    //If the volume is higher than the highstep
                    c->setDuration(m_partition->getTempo() / 16);
                    m_partition->addChord(c);
                    cout << m_partition->getDisplay() << endl;
                    cout << c->getDisplay() << endl;
                }
            }else{
                //We have to add some duration to the previous chord
                if(!c->isEmpty()){
                    m_partition->addDurationLastChord(step);
                }
            }
        }
        prec = c;
        //Sleeping for the shortest time in music theory(1 min / bpm / 16)
        usleep(1000 * 1000 * 60 / (m_partition->getTempo() * 16));
//        cout << "RECORDING" << endl;
    }

}

Partition *RecordThread::stop(){
    cout << "STOP" << endl;
    record = false;
    this->quit();
    m_analyze->close();
    return m_partition;
}
