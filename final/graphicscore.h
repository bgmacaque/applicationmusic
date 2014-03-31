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
 * \brief
 * \brief
 */\

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
    void addTablature(Tablature *t);
    void addNote(int x, int y, int number);
    void resizeEvent(QResizeEvent *event);
    void removeNotes();
    void setTabVisible(bool visible);
    int getTime();
    int getMaxTime();
    void addTime(int p_time);
    void setTime(int p_time);

protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *de);
    void mousePressEvent(QMouseEvent *event);


};

#endif // GRAPHICSCORE_H
