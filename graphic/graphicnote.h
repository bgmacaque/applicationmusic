#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <QWidget>
#include <QPainter>
#include <sstream>

class GraphicNote : public QWidget
{

private:
    int number;
    QPainter *painter;

public:
    GraphicNote(QWidget *parent, int num);
    void paintEvent(QPaintEvent *event);
    
};

#endif // GRAPHICNOTE_H
