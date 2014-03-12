#include "guitarstring.h"

GuitarString::GuitarString(std::string p_name, float p_lowFrequency, float p_highFrequency){
    m_name = p_name;
    m_lowFrequency = p_lowFrequency;
    m_highFrequency = p_highFrequency;
}

GuitarString::~GuitarString(){
}

bool GuitarString::playable(Note *n) const{
    return n->getFrequency() >= m_lowFrequency && n->getFrequency() <= m_highFrequency;
}
