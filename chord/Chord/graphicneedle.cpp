#include "graphicneedle.h"

GraphicNeedle::GraphicNeedle(QWidget *parent, int sizeX, int sizeY) : QWidget(parent)
{
    this->setMinimumSize(sizeX, sizeY);
    this->setMaximumSize(sizeX, sizeY);

    position_x = this->width()/2;
    position_y = 20;

    this->show();
    this->repaint();
}

void GraphicNeedle::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(0, 0, this->width(), this->height());

    //Now we trace lines
    painter->setBrush(QBrush(QColor(255, 0, 0)));
    painter->setPen(QColor(255, 0, 0));
    painter->drawLine(position_x, position_y, (int) this->width()/2, this->height());

}

/*void GraphicNeedle::goTo(int rotation)
{
    while(position!=rotation){

        //We modify the position of the needle
        if(position < rotation)
            position++;
        else
            position--;

        repaint();
        sleep(3);

    }
}*/

int GraphicNeedle::x(){
    return position_x;
}

int GraphicNeedle::y(){
    return position_y;
}

void GraphicNeedle::setX(int x)
{
    position_x = x;
}

void GraphicNeedle::setY(int y)
{
    position_y = y;
}

void GraphicNeedle::goRight()
{
    int x = position_x, y = position_y;

    position_x = qCos(0.1) * (x - this->width()/2) - qSin(0.1) * (y - this->height()) + this->width()/2;
    position_y = qSin(0.1) * (x - this->width()/2) + qCos(0.1) * (y - this->height()) + this->height();
}

void GraphicNeedle::goLeft()
{
    int x = position_x, y = position_y;

    position_x = qCos(-0.1) * (x - this->width()/2) - qSin(-0.1) * (y - this->height()) + this->width()/2;
    position_y = qSin(-0.1) * (x - this->width()/2) + qCos(-0.1) * (y - this->height()) + this->height();
}
