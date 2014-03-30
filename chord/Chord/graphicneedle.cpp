#include "graphicneedle.h"

GraphicNeedle::GraphicNeedle(QWidget *parent, int sizeX, int sizeY) : QWidget(parent)
{
    //We modify the size of the window
    this->setMinimumSize(sizeX, sizeY);
    this->setMaximumSize(sizeX, sizeY);

    //We compute the radius
    radius = qSqrt(qPow((this->width()/2 - this->width()/2), 2) + qPow((20 - this->height()), 2));

    //We set PI/2 to the initial angle (to be on the middle)
    angle = 1.57;

    this->show();
    this->repaint();

}

void GraphicNeedle::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    //We draw the white rectangle of the window
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(0, 0, this->width(), this->height());

    //Now we trace the line
    painter->setBrush(QBrush(QColor(255, 0, 0)));
    painter->setPen(QColor(255, 0, 0));

    //We draw the line by computing trigonometric coordinates
    painter->drawLine(radius * qCos(angle) + this->width()/2, this->height() - radius * qSin(angle), (int) this->width()/2, this->height());
}

qreal GraphicNeedle::getAngle(){
    return angle;
}

void GraphicNeedle::setAngle(qreal ang){
    angle = ang;
}

void GraphicNeedle::goLeft()
{
    //We increment the angle of rotation of 0.01 radian
    angle+=ROTATION_ANGLE;
}

void GraphicNeedle::goRight()
{
    //We decrement the angle of rotation of 0.01 radian
    angle-=ROTATION_ANGLE;
}
