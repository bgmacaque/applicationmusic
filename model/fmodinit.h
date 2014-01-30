#ifndef FMODINIT_H
#define FMODINIT_H
#include <string>
#include "fmod.hpp"

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

public:
    FModInit();
    ~FModInit();
    std::string init();
    std::string release();
    std::string errorCheck(FMOD_RESULT result);
};

#endif // FMODINIT_H
