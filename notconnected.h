#ifndef NOTCONNECTED_H
#define NOTCONNECTED_H

#include <QException>
#include <QString>

class NotConnected:QException
{
private:
    QString message;

public:
    NotConnected();

    /*!
     * \brief Describes the type of the error. Message might be shown to the user
     * \return A string describing the error
     */
    char * what() const throw();

    /*!
     * \brief To raise the exception
     */
    void raise();
};

#endif // NOTCONNECTED_H
