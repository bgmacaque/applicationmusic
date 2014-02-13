#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <fstream>
#include <iostream>
#include <stdlib.h>


/*!
 * \class Configuration configuration.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is used to modify and saved user's config
 */

class Configuration
{
private:
    QString* username;
    QString* password;

    bool password_saved;
    bool reloging_after_error;
    bool login_at_start;

    int reloging_after;

    std::string path;

public:
    Configuration();
    Configuration(QString u, QString pwd, bool pwd_saved, bool lg_strt,bool relg_after_err, int rlg_after);

    /*!
     * \brief Saves the current configuration in a config file
     */
    bool save();

    /*!
     * \brief A static method to load a config file
     * \param The path to the file
     * \return A config object
     */
     bool load();

    //We define all the setters
    void setUserName(QString *usr);
    void setPassword(QString *pwd);
    void setPasswordSaved(bool state);
    void setRelogingAfterError(bool state);
    void setRelogingAfter(int minutes);

    //We define all getters
    QString* getUserName();
    QString* getPassword();
    bool getPasswordSaved();
    bool getLogAtStart();
    bool getRelogingAfterError();
    int getRelogingAfter();

    //A special getter to get the decrypted password
    //QString* getDecryptedPass();
};

#endif // CONFIGURATION_H
