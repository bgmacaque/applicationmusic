#ifndef GRAPHICSCORE_H
#define GRAPHICSCORE_H

#include <QPainter>
#include "graphicnote.h"
#include "positionnednote.h"
#include "tablature.h"

/*!
 * \class GraphicScore graphicscore.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief Represent part of a tablature on the screen
 */

class GraphicScore : public QWidget
{

private:
//    QPainter *painter;
    std::vector<PositionnedNote *> *notes;
    int nb_lines;
    bool tabVisible;
    int time;
    int maxTime;

public:
    GraphicScore(QWidget *parent, int nb_line, int width, int height);
    GraphicScore(QWidget *parent, int nb_line, std::vector<PositionnedNote *> *n);
    void paintEvent(QPaintEvent *event);
    /*!
     * \brief Add a tablature to the score
     */
    void addTablature(Tablature *t);

    /*!
     * \brief Add a note to the score
     */
    void addNote(int x, int y, int number);
    void resizeEvent(QResizeEvent *event);

    /*!
     * \brief Remove all the notes of the score
     */
    void removeNotes();

    /*!
     * \brief Set if the score is visible or not
     */
    void setTabVisible(bool visible);

    /*!
     * \brief Get the current time in the application
     */
    int getTime();

    /*!
     * \brief Get the maximum time
     */
    int getMaxTime();

    /*!
     * \brief Add some time
     */
    void addTime(int p_time);

    /*!
     * \brief Set the time
     */
    void setTime(int p_time);

protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *de);
    void mousePressEvent(QMouseEvent *event);


};

#endif // GRAPHICSCORE_H
