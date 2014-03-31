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
    /*!
     * \brief Init the FMOD lib
     */
    std::string init();

    /*!
     * \brief Release the FMOD lib
     */
    std::string release();

    /*!
     * \brief Getter of m_system
     */
    FMOD::System *getSystem();

    /*!
     * \brief Getter of m_sound
     */
    FMOD::Sound *getSound();

    /*!
     * \brief Check if there is an error
     */
    std::string static errorCheck(FMOD_RESULT result);
};

#endif // FMODINIT_H
