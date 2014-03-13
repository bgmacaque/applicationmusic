#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <QWidget>
#include <QPainter>
#include <sstream>
#include <QDrag>
#include <QMimeData>
#include <QDragMoveEvent>
#include <ostream>
#include <QMessageBox>

/*!
 * \class Graphicnote graphicnote.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class stands for the graphical presentation of the note
 * \brief The linked click event on a graphical note is definied in this class
 */\

class GraphicNote : public QWidget
{

private:
    int number;
    QPainter *painter;
    QDrag *drager;
    QWidget *parent;

public:
    GraphicNote(QWidget *parent, int num);
    void paintEvent(QPaintEvent *event);
    int getNumber();
    QDrag* getDrager();

protected:
    void mousePressEvent(QMouseEvent *event);
    
};

#endif // GRAPHICNOTE_H
