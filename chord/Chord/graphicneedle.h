#ifndef GRAPHICNEEDLE_H
#define GRAPHICNEEDLE_H

#define ROTATION_ANGLE 0.01

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <qmath.h>

/*!
 * \brief The GraphicNeedle class
 * A needle to represent the position of the note relative to the current played note
 * \author ALBERT Vincent, NAJIMI Adonis, STERN Valentin
 */

class GraphicNeedle : public QWidget
{
    Q_OBJECT

private:

    QPainter *painter;

    /*!
     * \brief radius
     * The radius of the needle
     */
    int radius;

    /*!
     * \brief angle
     * The angle of the rotation
     */
    qreal angle;

public:
    /*!
     * \brief GraphicNeedle A constructor
     * \param parent The parent of the window
     * \param sizeX The width of the window
     * \param sizeY The height of the window
     */
    GraphicNeedle(QWidget *parent = 0, int sizeX = 200, int sizeY = 100);

    /*!
     * \brief paintEvent A method to paint the window and its components
     * \param event
     */
    void paintEvent(QPaintEvent *event);
    
public slots:

    /*!
     * \brief goRight Rotate the needle to the right for 0.01 radian
     */
    void goRight();

    /*!
     * \brief goLeft Rotate the needle to the left for 0.01 radian
     */
    void goLeft();

    /*!
     * \brief getAngle Return the current angle of the rotation
     * \return The angle of the rotation in the current moment
     */
    qreal getAngle();

    /*!
     * \brief setAngle Set a nex angle for the rotation
     * \param ang The new angle for the rotation
     */
    void setAngle(qreal ang);
};

#endif // GRAPHICNEEDLE_H
