#ifndef FMODINIT_H
#define FMODINIT_H
#include <string>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <cstring>

/*!
 * \class FModInit fmodinit.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief Class used to init the library
 */
class FModInit{
private:
    FMOD::System *m_system;
    FMOD::Sound *m_sound;

public:
    FModInit();
    ~FModInit();
    std::string init();
    std::string release();
    FMOD::System *getSystem();
    FMOD::Sound *getSound();
    std::string static errorCheck(FMOD_RESULT result);
};

#endif // FMODINIT_H
