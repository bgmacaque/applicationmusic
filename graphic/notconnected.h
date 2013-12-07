#ifndef NOTCONNECTED_H
#define NOTCONNECTED_H

#include <QException>
#include <QString>

class NotConnected
{
private:
    QString message;

public:
    NotConnected();

    /*!
     * \brief Describes the type of the error. Message might be shown to the user
     * \return A string describing the error
     */
    virtual const char * what() const throw();
};

#endif // NOTCONNECTED_H
