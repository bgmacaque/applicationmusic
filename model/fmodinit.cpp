#include "fmodinit.h"

FModInit::FModInit(){
}


FModInit::~FModInit(){
    this->release();
}

std::string FModInit::release(){

}

std::string FModInit::init(){
    std::string retour = "";
    FMOD_RESULT result;
    result = FMOD::System_Create(&this->m_system);
}

std::string errorCheck(FMOD_RESULT result){
    std::string retour = "";
    if(result != FMOD_OK){
        retour = "Error when using FMOD : " << result;
    }
    return retour;
}
