#include "notes.h"

//Just for debug
#include <iostream>

//Just for debug
using namespace std;



Notes::Notes(){
    cout << "COUCOU" << endl;
}

Notes *Notes::get_instance(){
    if(m_instance == NULL){
        m_instance = new Notes();
    }else{
        cout << "Already created" << endl;
    }
    return m_instance;
}
