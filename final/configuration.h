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

    /*!
     * \brief The username of the user
     */
    QString* username;

    /*!
     * \brief The password of the user
     */
    QString* password;

    /*!
     * \brief True if the password has been saved
     */
    bool password_saved;

    /*!
     * \brief True if the application should reloging after an error
     */
    bool reloging_after_error;

    /*!
     * \brief True if the application should log at start
     */
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

    /*!
     * \brief Setter for the username
     */
    void setUserName(QString *usr);

    /*!
     * \brief Setter for the password
     */
    void setPassword(QString *pwd);

    /*!
     * \brief Setter for the password saving state
     */
    void setPasswordSaved(bool state);

    /*!
     * \brief Setter for the reloging after error behavior
     */
    void setRelogingAfterError(bool state);

    /*!
     * \brief The duration in time of the chord
     */
    void setRelogingAfter(int minutes);

    /*!
     * \brief Getter for the username
     */
    QString* getUserName();

    /*!
     * \brief Getter for the password
     */
    QString* getPassword();

    /*!
     * \brief Getter for the password saved statement
     */
    bool getPasswordSaved();

    /*!
     * \brief Getter for the logging at start behavior
     */
    bool getLogAtStart();

    /*!
     * \brief Getter for the reloging after error behavior statement
     */
    bool getRelogingAfterError();

    /*!
     * \brief Getter for the
     */
    int getRelogingAfter();

    //A special getter to get the decrypted password
    //QString* getDecryptedPass();
};

#endif // CONFIGURATION_H
