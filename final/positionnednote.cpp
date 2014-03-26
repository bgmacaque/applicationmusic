#include "positionnednote.h"

PositionnedNote::PositionnedNote(QWidget *parent, GraphicNote *n, QPoint *p) : QWidget(parent), note(n), position(p)
{
}

GraphicNote* PositionnedNote::getNote()
{
    return note;
}

QPoint* PositionnedNote::getPos()
{
    return position;
}

void PositionnedNote::setPosition(QPoint *point){
    position = point;
    note->move(*point);
}

void PositionnedNote::paintEvent(QPaintEvent *event)
{
    note->repaint();
}
