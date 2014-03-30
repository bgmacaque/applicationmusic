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
    int rayon;
    qreal angle;

public:
    GraphicNeedle(QWidget *parent = 0, int sizeX = 200, int sizeY = 100);
    void paintEvent(QPaintEvent *event);
    
signals:
    
public slots:
    void goRight();
    void goLeft();
    qreal getAngle();
    void setAngle(qreal ang);
    
};

#endif // GRAPHICNEEDLE_H
