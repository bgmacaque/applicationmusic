#ifndef GRAPHICSCORE_H
#define GRAPHICSCORE_H

#include <QPainter>
#include "graphicnote.h"

class GraphicScore : public QWidget
{

private:
    QPainter *painter;
    std::vector<GraphicNote> *notes;
    int nb_lines;

public:
    GraphicScore(QWidget *parent, int nb_line);
    GraphicScore(QWidget *parent, int nb_line, std::vector<GraphicNote> *n);
    void paintEvent(QPaintEvent *event);

};

#endif // GRAPHICSCORE_H
