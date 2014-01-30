#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <fstream>

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
    QString username;
    QString password;

    bool password_saved;
    bool reloging_after_error;

    int reloging_after;

public:
    Configuration();
    Configuration(QString u, QString pwd, bool pwd_saved, bool relg_after_err, int rlg_after);

    /*!
     * \brief Saves the current configuration in a config file
     */
    void save();

    /*!
     * \brief A static method to load a config file
     * \param The path to the file
     * \return A config object
     */
    static Configuration load(std::string path);

    //We define all the setters
    void setUserName(QString usr);
    void setPassword(QString pwd);
    void setPasswordSaved(bool state);
    void setRelogingAfterError(bool state);
    void setRelogingAfter(int minutes);

    //We define all getters
    QString getUserName();
    QString getPassword();
    bool getPasswordSaved();
    bool getRelogingAfterError();
    int getRelogingAfter();
};

#endif // CONFIGURATION_H
