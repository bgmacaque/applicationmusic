#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <QWidget>
#include <QPainter>
#include <sstream>
#include <QDrag>
#include <QMimeData>
#include <QDragMoveEvent>
#include <ostream>
#include <QMessageBox>

class GraphicNote : public QWidget
{

private:
    int number;
    QPainter *painter;
    QDrag *drager;
    QWidget *parent;

public:
    GraphicNote(QWidget *parent, int num);
    void paintEvent(QPaintEvent *event);
    int getNumber();
    QDrag* getDrager();

protected:
    void mousePressEvent(QMouseEvent *event);
    
};

#endif // GRAPHICNOTE_H
