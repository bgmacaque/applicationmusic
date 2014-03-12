#include "guitarstring.h"

GuitarString::GuitarString(Analyze *analyze){
    m_analyze = analyze;
}

GuitarString::~GuitarString(){
    delete m_analyze;
}
