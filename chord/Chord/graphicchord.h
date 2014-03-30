#ifndef GRAPHICCHORD_H
#define GRAPHICCHORD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QCoreApplication>
#include "graphicneedle.h"

#define TEMPS_PAUSE 5

/*!
 * \brief The GraphicChord class
 * \author ALBERT Vincent, NAJIMI Adonis, STERN Valentin
 */

class GraphicChord : public QWidget
{
    Q_OBJECT
    
private:

    /*!
     * \brief note_label
     * A label to display the current played note
     */
    QLabel *note_label;

    /*!
     * \brief note_needle
     * An object to show the position relative to the current note
     */
    GraphicNeedle *note_needle;

    /*!
     * \brief status
     * The status of the tuner. There is 3 status :
     * -1 : The needle is to the lefts
     * 0 : the needle is at the middle
     * 1 : the needle is at the right
     */
    int status;

    //Some private methods to modifiy the needle-shower

    /*!
     * \brief goToLeft
     * Go to the left for 45°
     */
    void goToLeft();

    /*!
     * \brief goToRight
     * Go to the right for 45°
     */
    void goToRight();

    /*!
     * \brief goAndStay
     * Move a bit but stay at the same position
     */
    void goAndStay();

    /*!
     * \brief needleGoTo Put the needle to the right place thans to the position (-1, 0, 1)
     * \param pos New status of the needle (-1, 0 or 1)
     */
    void needleGoTo(int pos);

public:
    /*!
      * \brief GraphicChord
      * A constructor to change the beginning note
      * \param parent The parent of the window
      * \param first_note The first note of the tuner
      */
     GraphicChord(QWidget *parent = 0, QString first_note = "A");

     /*!
      * \brief setTo
      * Places the chord to the note selected
      */
     void setTo(QString note, int dest_needle);

     /*!
      * \brief sleep
      * \param ms Number of ms the application has to play
      */
     static void sleep(int ms);
};

#endif // GRAPHICCHORD_H
