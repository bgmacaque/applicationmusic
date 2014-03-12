#include "guitarstring.h"


#include <iostream>
using namespace std;


GuitarString::GuitarString(std::string p_name, std::string p_noteName, int p_nbFrets){
    m_name = p_name;
    Notes *INotes = Notes::get_instance();
    Note *n = INotes->searchNote(p_noteName);
    if(n){
        m_lowFrequency = n->getFrequency();
        m_nbFrets = p_nbFrets;
        Note **notes = INotes->getNotesFrets(p_noteName, p_nbFrets);
        m_frets = new Fret*[p_nbFrets];
        int i(0);
        for(i = 0 ; i < p_nbFrets ; i++){
            m_frets[i] = new Fret(i, notes[i]);
            cout << m_frets[i]->getNote()->getName() << "," << m_frets[i]->getNumber() << endl;
        }
        m_highFrequency = m_frets[p_nbFrets - 1]->getNote()->getFrequency();

    }else{
        m_lowFrequency = 0;
        m_highFrequency = 0;
        m_nbFrets = 0;
        m_frets = 0;
    }
}

GuitarString::~GuitarString(){
    int i(0);
    for(i = 0 ; i < m_nbFrets ; i++){
        delete m_frets[i];
    }
    delete[] m_frets;
}

bool GuitarString::playable(Note *n) const{
    return n->getFrequency() >= m_lowFrequency && n->getFrequency() <= m_highFrequency;
}
