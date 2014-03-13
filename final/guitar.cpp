#include "guitar.h"
#include <iostream>

using namespace std;


Guitar *Guitar::m_instance = NULL;

Guitar::Guitar(){
    cout << "Construction " << endl;
    m_nbStrings = 6;
}

Guitar::~Guitar(){

}

void Guitar::kill(){
    delete m_instance;
}

Fret **Guitar::getFrets(Chord *chord) const{
    int i;
    int j=0;
    std::vector<Note*> notes = chord->getNotes();
    Fret **frets = new Fret*[chord->notesNumber()];
    for (i = 0 ; i < chord->notesNumber() ; i++){
        while(j < m_nbStrings){
            if(m_strings[j]->playable( notes.at(i) )){
                frets[i] = m_strings[j]->getFret(notes.at(i));
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
