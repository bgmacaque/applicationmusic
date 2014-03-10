#ifndef POSITIONNEDNOTE_H
#define POSITIONNEDNOTE_H

#include "graphicnote.h"
#include <QWidget>

class PositionnedNote : public QWidget
{
private:
    GraphicNote *note;
    QPoint *position;

public:
    PositionnedNote(QWidget *parent, GraphicNote *n, QPoint *p);
    GraphicNote *getNote();
    QPoint *getPos();
    void paintEvent(QPaintEvent *event);
};

#endif // POSITIONNEDNOTE_H
