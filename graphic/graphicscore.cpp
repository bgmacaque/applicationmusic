#include "graphicscore.h"

GraphicScore::GraphicScore(QWidget *parent, int nb_line) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = new std::vector<GraphicNote>();


    this->setMinimumSize(600, 100);
    this->setMaximumSize(600, 100);

    this->repaint();
    this->show();
}

GraphicScore::GraphicScore(QWidget *parent, int nb_line, std::vector<GraphicNote> *n) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = n;


    this->setMinimumSize(600, 100);
    this->setMaximumSize(600, 100);

    this->repaint();
    this->show();
}

void GraphicScore::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setBrush(QBrush(QColor(255, 230, 155)));
    painter->drawRect(0, 0, this->width(), this->height());

    //Now we trace lines
    painter->setBrush(QBrush(QColor(255, 0, 0)));
    painter->setPen(QColor(154, 0, 0));
    for(int i=0; i<nb_lines; i++)
    {
        painter->drawLine(0, this->height()/nb_lines * (i+1), this->width(), this->height()/nb_lines * (i+1));
    }
}
