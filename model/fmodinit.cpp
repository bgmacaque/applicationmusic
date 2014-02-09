#include "fmodinit.h"
#define OUTPUTRATE 48000


FModInit::FModInit(){
    m_system = 0;
    m_sound = 0;
}

FModInit::~FModInit(){
    this->release();
}

std::string FModInit::release(){
    std::string retour = "";
    m_system->release();
    m_sound->release();
    return retour;
}

std::string FModInit::init(){
    std::string retour = "";
    unsigned int version(0);
    int output_freq(0);
    FMOD_RESULT result;
    FMOD_CREATESOUNDEXINFO exinfo;

    result = FMOD::System_Create(&m_system);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    result = m_system->getVersion(&version);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    if(version < FMOD_VERSION){
        retour = "You're using an old version of FMOD, please download at least the version : " + version;
        return retour;
    }



    //Hard coded for tests but need to be used with parameters
    result = m_system->setOutput(FMOD_OUTPUTTYPE_PULSEAUDIO);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    //Hard coded too
    result = m_system->setDriver(0);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }


    //Also hard coded, it's bad
    result = m_system->setSoftwareFormat(OUTPUTRATE, FMOD_SOUND_FORMAT_PCM16, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    result = m_system->init(32, FMOD_INIT_NORMAL, 0);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    m_system->getSoftwareFormat(&output_freq, 0,0,0,0,0);

    //We know that we only have to use one sound
    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = OUTPUTRATE;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;

    result = m_system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &m_sound);
    retour = this->errorCheck(result);
    if(retour != ""){
        return retour;
    }

    return retour;
}



std::string FModInit::errorCheck(FMOD_RESULT result){
    std::string retour = "";
    if(result != FMOD_OK){
        retour = "Error when using FMOD : " + result;
    }
    return retour;
}


FMOD::Sound *FModInit::getSound(){
    return m_sound;
}


FMOD::System *FModInit::getSystem(){
    return m_system;
}
