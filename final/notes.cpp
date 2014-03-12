#include "notes.h"

//Just for debug
#include <iostream>

//Just for debug
using namespace std;

//Initialisation of the static instance
Notes *Notes::m_instance = NULL;

Notes::Notes(){
    cout << "COUCOU" << endl;
}

Notes *Notes::get_instance(){
    if(m_instance == NULL){
        m_instance = new Notes();
    }else{
        cout << "Already created" << endl;
    }
    cout << "Instance return" << endl;
    return Notes::m_instance;
}
