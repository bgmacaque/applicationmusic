#include "graphicneedle.h"

#define ROTATION_ANGLE 0.01

GraphicNeedle::GraphicNeedle(QWidget *parent, int sizeX, int sizeY) : QWidget(parent)
{
    this->setMinimumSize(sizeX, sizeY);
    this->setMaximumSize(sizeX, sizeY);

    position_x = this->width()/2;
    position_y = 20;

    rayon = qSqrt(qPow((position_x - this->width()/2), 2) + qPow((position_y - this->height()), 2));
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
    //painter->drawLine(rayon * qCos(angle) + this->width()/2, rayon * qSin(angle), (int) this->width()/2, this->height());
    painter->drawLine(rayon * qCos(angle) + this->width()/2, this->height() - rayon * qSin(angle), (int) this->width()/2, this->height());

    //std::cout << "RAYON : " << rayon << ", ANGLE : " << angle << ", X : " << position_x << ", Y : " << rayon * qSin(angle) - (height() - 20) ;

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

qreal GraphicNeedle::getAngle(){
    return angle;
}

void GraphicNeedle::setAngle(qreal ang){
    angle = ang;
}

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

void GraphicNeedle::goLeft()
{
    //int x, y;

    //x = qCos(0.1) * (position_x - this->width()/2) - qSin(0.1) * (position_y - this->height()) + this->width()/2;
    //y = qSin(0.1) * (position_x - this->width()/2) + qCos(0.1) * (position_y - this->height()) + this->height();

    //position_x = x;
    //position_y = y;
    /*position_x += rayon * qCos(0.05);
    position_y = rayon * qSin(0.05);*/
    angle+=ROTATION_ANGLE;

    position_x = rayon * qCos(angle);
    position_y = rayon * qSin(angle);
}

void GraphicNeedle::goRight()
{
    /*int x, y;

    x = qCos(-0.1) * (position_x - this->width()/2) - qSin(-0.1) * (position_y - this->height()) + this->width()/2;
    y = qSin(-0.1) * (position_x - this->width()/2) + qCos(-0.1) * (position_y - this->height()) + this->height();

    position_x = x;
    position_y = y;*/

    /*position_x -= rayon * qCos(0.05);
    position_y = rayon * qSin(0.05);*/


    angle-=ROTATION_ANGLE;
    position_x = rayon * qCos(angle);
    position_y = rayon * qSin(angle);
}
