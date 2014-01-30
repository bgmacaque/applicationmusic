#include "configuration.h"

Configuration::Configuration()
{
    path = "../user.conf";
    if(!load())
    {
        username = new QString("");

        password_saved = false;
        reloging_after_error = false;

        reloging_after = false;
    }
}

Configuration::Configuration(QString u, QString pwd, bool pwd_saved, bool relg_after_err, int rlg_after):username(&u), password(&pwd), password_saved(pwd_saved), reloging_after_error(relg_after_err), reloging_after(rlg_after)
{
    path = "../user.conf";
}

bool Configuration::load()
{
    std::ifstream config(path.c_str(), std::ios::in);

    if(config)
    {
        std::string usr, pwd, pwd_saved, rlg_after_err, rlg_after;

        //We read all data
        std::getline(config, usr);
        std::getline(config, pwd);
        std::getline(config, pwd_saved);
        std::getline(config, rlg_after_err);
        std::getline(config, rlg_after);

        //Then we create the object
        username = new QString(usr.c_str());
        password = new QString(pwd.c_str());

        //Booleans are transposed in int during the writting
        if(pwd_saved == "1")
            password_saved = true;
        else
            password_saved = false;

        if(rlg_after_err == "1")
            reloging_after_error = true;
        else
            reloging_after_error = false;

        if(reloging_after_error)
            reloging_after= atoi(rlg_after.c_str());
        else
            reloging_after=1;

        config.close();

        return true;
    }

    return false;
}

bool Configuration::save()
{
    std::ofstream config(path.c_str(), std::ios::out | std::ios::trunc);

    if(config){
        config << username->toStdString() << std::endl;
        config << password->toStdString() << std::endl;
        config << password_saved << std::endl;
        config << reloging_after_error << std::endl;
        config << reloging_after << std::endl;

        config.close();
        return true;
    }

    return false;
}








//GETTERS AND SETTERS

void Configuration::setPassword(QString *pwd)
{
    this->password = pwd;
}

void Configuration::setPasswordSaved(bool state)
{
    this->password_saved = state;
}

void Configuration::setRelogingAfter(int minutes)
{
    this->reloging_after = minutes;
}

void Configuration::setRelogingAfterError(bool state)
{
    this->reloging_after_error = state;
}

void Configuration::setUserName(QString* usr)
{
    this->username = usr;
}

QString* Configuration::getPassword()
{
    return this->password;
}

bool Configuration::getPasswordSaved()
{
    return this->password_saved;
}

int Configuration::getRelogingAfter()
{
    return this->reloging_after;
}

bool Configuration::getRelogingAfterError()
{
    return this->reloging_after_error;
}

QString* Configuration::getUserName()
{
    return this->username;
}


