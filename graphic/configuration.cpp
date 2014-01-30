#include "configuration.h"

Configuration::Configuration()
{

}

Configuration::Configuration(QString u, QString pwd, bool pwd_saved, bool relg_after_err, int rlg_after):username(u), password(pwd), password_saved(pwd_saved), reloging_after_error(relg_after_err), reloging_after(rlg_after)
{

}

Configuration::setPassword(QString pwd)
{
    this->password = pwd;
}

Configuration::setPasswordSaved(bool state)
{
    this->password_saved = state;
}

Configuration::setRelogingAfter(int minutes)
{
    this->reloging_after = minutes;
}

Configuration::setRelogingAfterError(bool state)
{
    this->reloging_after_error = state;
}

Configuration::setUserName(QString usr)
{
    this->username = usr;
}

QString Configuration::getPassword()
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

QString Configuration::getUserName()
{
    return this->username;
}
