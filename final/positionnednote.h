#ifndef POSITIONNEDNOTE_H
#define POSITIONNEDNOTE_H

#include "graphicnote.h"
#include <QWidget>

/*!
 * \class PositionnedNote positionnednote.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class stand
 * \brief The attribut note is the GraphicalObjet that represent a note in a partition
 * \brief The attribut position is the position the GraphicNote should be drawn
 */\

class PositionnedNote : public QWidget
{
private:
    GraphicNote *note;
    QPoint *position;

public:
    PositionnedNote(QWidget *parent, GraphicNote *n, QPoint *p);
    GraphicNote *getNote();
    QPoint *getPos();
    void paintEvent(QPaintEvent *event);
    void setPosition(QPoint *point);
    ~PositionnedNote();
};

#endif // POSITIONNEDNOTE_H
