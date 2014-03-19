#include "guitarstring.h"


#include <iostream>
using namespace std;

GuitarString::GuitarString(){

}

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

//        std::cout << p_name << std::endl;
        for(i = 0 ; i < p_nbFrets ; i++){
            m_frets[i] = new Fret(i, notes[i]);
//            std::cout << m_frets[i]->getNote()->getName() << std::endl;
        }
//        std::cout << "--------------" << std::endl;
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

Fret *GuitarString::getFret(Note *n) const{
    int i(0);
    Fret *f = 0;
    bool found = false;
    while(i < m_nbFrets && !found){
        if(m_frets[i]->getNote()->getName().compare(n->getName()) == 0){
            found = true;
            f = m_frets[i];
        }
        i++;
    }
    return f;
}

bool GuitarString::playable(Note *n) const{
//    std::cout << n->getFrequency() << ", low" << m_lowFrequency << std::endl;
//    std::cout << n->getFrequency() << ", high" << m_highFrequency << std::endl;
    return n->getFrequency() >= m_lowFrequency && n->getFrequency() <= m_highFrequency;
}
