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

Guitar *Guitar::get_instance(){
    if(m_instance == NULL){
        m_instance = new Guitar();
    }
    return m_instance;
}
