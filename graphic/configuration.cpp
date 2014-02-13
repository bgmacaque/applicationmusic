#include "configuration.h"

Configuration::Configuration()
{
    path = "../user.conf";
    username = new QString("");
    password = new QString("");

    password_saved = false;
    reloging_after_error = false;
    login_at_start = false;

    reloging_after = false;
}

Configuration::Configuration(QString u, QString pwd, bool pwd_saved, bool lg_strt, bool relg_after_err, int rlg_after):username(&u), password(&pwd), password_saved(pwd_saved), login_at_start(lg_strt),reloging_after_error(relg_after_err), reloging_after(rlg_after)
{
    path = "../user.conf";
}

bool Configuration::load()
{
    std::ifstream config(path.c_str(), std::ios::in);

    if(config)
    {
        std::string usr, pwd, pwd_saved, lg_str, rlg_after_err, rlg_after;

        //We read all data
        std::getline(config, usr);
        std::getline(config, pwd);
        std::getline(config, pwd_saved);
        std::getline(config, lg_str);
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

        if(lg_str == "1")
            login_at_start = true;
        else
            login_at_start = false;

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
    std::ofstream conf(path.c_str(), std::ios::out | std::ios::trunc);

    if(conf){

        conf << username->toStdString() << std::endl;
        conf << password->toStdString() << std::endl;
        conf << password_saved << std::endl;
        conf << login_at_start << std::endl;
        conf << reloging_after_error << std::endl;
        conf << reloging_after << std::endl;

        conf.close();
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

bool Configuration::getLogAtStart()
{
    return this->login_at_start;
}

//QString* Configuration::getDecryptedPass()
//{
////    rsa.genererCles(2048);

////    QString* decrypted = new QString(rsa.dechiffrerAvecClePrivee(password->toStdString()).c_str());

////    return decrypted;
//}


