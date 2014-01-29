#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "noskin.h"

/*!
 * \class Controller controller.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is the controller, the link between the view and the model
 */

class Controller : public QObject
{

    friend class NoSkin;
    Q_OBJECT

private:

    bool playing;
    bool recording;
    bool saved;
    NoSkin *frame;

public:
    Controller(NoSkin *frame);

    /*!
     * \brief The function that active the controller
     */
    void active();

public slots:
    void play();
    void record();
    void save();
};

#endif // CONTROLLER_H
