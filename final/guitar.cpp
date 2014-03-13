#include "guitar.h"
#include <iostream>

using namespace std;


Guitar *Guitar::m_instance = NULL;

Guitar::Guitar(){
    cout << "Construction " << endl;
}

Guitar::~Guitar(){

}

void Guitar::kill(){
    delete m_instance;
}

*Fret[]::get_frets(*chord chord){
    int i;
    int j=0;
    *Fret[] frets=new *Fret[chord.length];
    for (i=0;i<chord.length;i++){
        for (j=0;j<6;j++){
            if (m_instance.strings[j].playable) frets[i]=m_instance.strings[j].get_fret();
        }
    }
}

Guitar *Guitar::get_instance(){
    if(m_instance == NULL){
        m_instance = new Guitar();
    }
    return m_instance;
}
