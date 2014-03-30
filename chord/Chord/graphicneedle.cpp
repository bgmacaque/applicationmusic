#include "graphicneedle.h"

GraphicNeedle::GraphicNeedle(QWidget *parent, int sizeX, int sizeY) : QWidget(parent)
{
    this->setMinimumSize(sizeX, sizeY);
    this->setMaximumSize(sizeX, sizeY);

    radius = qSqrt(qPow((this->width()/2 - this->width()/2), 2) + qPow((20 - this->height()), 2));
    angle = 1.57;

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
    angle+=ROTATION_ANGLE;
}

void GraphicNeedle::goRight()
{
    angle-=ROTATION_ANGLE;
}
