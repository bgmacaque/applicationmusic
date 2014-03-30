#ifndef GRAPHICNEEDLE_H
#define GRAPHICNEEDLE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <qmath.h>
#include <iostream>

class GraphicNeedle : public QWidget
{
    Q_OBJECT
private:
    QPainter *painter;
    int position_x;
    int position_y;

    int rayon;
    qreal angle;

public:
    GraphicNeedle(QWidget *parent = 0, int sizeX = 200, int sizeY = 100);
    void paintEvent(QPaintEvent *event);
    
signals:
    
public slots:
    //void goTo(int rotation);
    void goRight();
    void goLeft();
    int x();
    int y();
    void setX(int x);
    void setY(int y);
    qreal getAngle();
    void setAngle(qreal ang);
    
};

#endif // GRAPHICNEEDLE_H
