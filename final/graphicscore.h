#ifndef GRAPHICSCORE_H
#define GRAPHICSCORE_H

#include <QPainter>
#include "graphicnote.h"
#include "positionnednote.h"

/*!
 * \class GraphicScore graphicscore.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief
 * \brief
 */\

class GraphicScore : public QWidget
{

private:
    QPainter *painter;
    std::vector<PositionnedNote *> *notes;
    int nb_lines;

public:
    GraphicScore(QWidget *parent, int nb_line);
    GraphicScore(QWidget *parent, int nb_line, std::vector<PositionnedNote *> *n);
    void paintEvent(QPaintEvent *event);

protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *de);
    void mousePressEvent(QMouseEvent *event);
    void addNote(int x, int y, int number);
};

#endif // GRAPHICSCORE_H
