#ifndef GRAPHICSCORE_H
#define GRAPHICSCORE_H

#include <QPainter>
#include "graphicnote.h"
#include "positionnednote.h"

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

};

#endif // GRAPHICSCORE_H
