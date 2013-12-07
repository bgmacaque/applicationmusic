#ifndef NOTJSONEXCEPTION_H
#define NOTJSONEXCEPTION_H

#include <QException>
#include <QString>

class NotJSONException:QException
{
private:
    QString message;

public:
    NotJSONException();

    /*!
     * \brief Describes the type of the error. Message might be shown to the user
     * \return A string describing the error
     */
    virtual const char * what() const throw();
};

#endif // NOTJSONEXCEPTION_H
