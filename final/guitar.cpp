#include "guitar.h"
#include <iostream>

using namespace std;


Guitar *Guitar::m_instance = NULL;

Guitar::Guitar(){
    m_nbStrings = 6;
    m_strings = new GuitarString*[m_nbStrings];
    m_strings[0] = new GuitarString("E", "E3", 25);
    m_strings[1] = new GuitarString("A", "A4", 25);
    m_strings[2] = new GuitarString("D", "D4", 25);
    m_strings[3] = new GuitarString("G", "G4", 25);
    m_strings[4] = new GuitarString("B", "B5", 25);
    m_strings[5] = new GuitarString("e", "E5", 25);
}

Guitar::~Guitar(){
    int i(0);
    for(i = 0 ; i < m_nbStrings ; i++){
        delete m_strings[i];
    }
    delete[] m_strings;
}

void Guitar::kill(){
    delete m_instance;
}

Fret **Guitar::getFrets(Chord *chord) const{
    int i;
    int j=0;
    std::vector<Note*> notes = chord->getNotes();
    Fret **frets = new Fret*[chord->notesNumber()];
    Fret *fret;
    for (i = 0 ; i < chord->notesNumber() ; i++){
        while(j < m_nbStrings){
            if(m_strings[j]->playable( notes.at(i) )){
                fret = m_strings[j]->getFret(notes.at(i));
                if(fret != 0){
                    frets[i] = fret;
                }
            }
            j++;
        }
    }
    return frets;
}

Guitar *Guitar::get_instance(){
    if(m_instance == NULL){
        m_instance = new Guitar();
    }
    return m_instance;
}
