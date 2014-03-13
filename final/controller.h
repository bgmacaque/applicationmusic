#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "noskin.h"
#include "confwindow.h"
#include "partition.h"
#include "fmodinit.h"
#include "recordthread.h"
#include "controller.h"
#include <QMessageBox>
#include "tablature.h"

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

    /*!
     * \brief Boolean for the statement of the controller, true if playing sound
     */
    bool playing;

    /*!
     * \brief Boolean for the statement of the recording, true if recording
     */
    bool recording;

    /*!
     * \brief Boolean for the file statement, true if it has been saved since last modification
     */
    bool saved;

    /*!
     * \brief NoSkin for the application frame
     */
    NoSkin *frame;

    /*!
     * \brief Current partition for the controller
     */
    Partition *partition;

    /*!
     * \brief Current analyze for the controller
     */
    Analyze *analyze;

    /*!
     * \brief Instance of FModInit to initialiaze the FMOD library
     */
    FModInit *fmodlib;

    /*!
     * \brief Instance of RecordThread for the recording procedure
     */
    RecordThread *recordThread;

    /*!
     * \brief The tablature that will be altered by the controller
     */
    Tablature *tablature;

public:
    Controller(NoSkin *frame);

    /*!
     * \brief The function that active the controller
     */
    void active();
    ~Controller();

public slots:

    /*!
     * \brief If the partition lecture is paused (re)start it
     * \brief Else pause it
     */
    void play();

    /*!
     * \brief If recording, stop the recording process
     * \brief Else start recording
     */
    void record();

    /*!
     * \brief Box to inform if the user want his password to be saved
     */
    void save();

    /*!
     * \brief Box to inform if the user want his password to be saved
     */
    void openConf();

    /*!
     * \brief Try to connect the user to the website
     * \exception NotConnected If it doesn't work
     */
    void connectToWeb();
};

#endif // CONTROLLER_H
