#include "graphicneedle.h"

GraphicNeedle::GraphicNeedle(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(200, 100);
    this->setMaximumSize(200, 100);

    position_x = this->width()/2 - 20;
    position = position_x;
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

qreal GraphicNeedle::posX()
{
    return this->position;
}

void GraphicNeedle::goForward()
{
    int x = position_x, y = position_y;

    position_x = qCos(1) * (x - this->width()/2) - qSin(1) * (y - this->height()) + this->width()/2;
    position_y = qSin(1) * (x - this->width()/2) + qCos(1) * (y - this->height()) + this->height();

    position++;
}

void GraphicNeedle::goBack()
{
    int x = position_x, y = position_y;

    position_x = qCos(-1) * (x - this->width()/2) - qSin(-1) * (y - this->height()) + this->width()/2;
    position_y = qSin(-1) * (x - this->width()/2) + qCos(-1) * (y - this->height()) + this->height();

    position--;
}
