#ifndef GRAPHICNEEDLE_H
#define GRAPHICNEEDLE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <qmath.h>

class GraphicNeedle : public QWidget
{
    Q_OBJECT
private:
    QPainter *painter;
    int position_x;
    int position_y;
    int position;

public:
    GraphicNeedle(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    
signals:
    
public slots:
    //void goTo(int rotation);
    void goBack();
    void goForward();
    int posX();
    
};

#endif // GRAPHICNEEDLE_H
