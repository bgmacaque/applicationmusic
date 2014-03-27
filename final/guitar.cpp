#include "guitar.h"
#include <iostream>

using namespace std;


Guitar *Guitar::m_instance = NULL;

Guitar::Guitar(){
    m_nbStrings = 6;
    m_strings = new GuitarString*[m_nbStrings];
    m_strings[0] = new GuitarString("E", "E2", 25, 0);
    m_strings[1] = new GuitarString("A", "A2", 25, 1);
    m_strings[2] = new GuitarString("D", "D3", 25, 2);
    m_strings[3] = new GuitarString("G", "G3", 25, 3);
    m_strings[4] = new GuitarString("B", "B3", 25, 4);
    m_strings[5] = new GuitarString("e", "E4", 25, 5);
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

Fret **Guitar::getFrets(Chord *chord, int *realSize) const{
    int i = 0;
    int j = 0;
    std::vector<Note*> notes = chord->getNotes();
    Fret **frets = new Fret*[chord->notesNumber()];
    Fret *fret;
    bool found = false;
    while(i < chord->notesNumber() && j < m_nbStrings){
        found = false;
        while(j < m_nbStrings && !found){
            if(m_strings[j]->playable( notes.at(i) )){
                fret = m_strings[j]->getFret(notes.at(i));
                if(fret != 0){
                    frets[i] = fret;
                    found = true;
                }
            }
            j++;
        }
        if(found){
            i++;
        }
    }
    Fret **retour = new Fret*[i];
    if(i < chord->notesNumber()){
        for(j = 0 ; j < i ; j++){
            retour[j] = frets[j];
        }
        *realSize = i;
    }else{
        *realSize = chord->getNotes().size();
        retour = frets;
    }
    return retour;
}

float Guitar::getHighestFrequency(){
    return m_strings[m_nbStrings - 1]->getHighFrequency();
}

float Guitar::getLowestFrequency(){

    return m_strings[0]->getLowFrequency();
}

Guitar *Guitar::get_instance(){
    if(m_instance == NULL){
        m_instance = new Guitar();
    }
    return m_instance;
}
