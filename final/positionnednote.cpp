#include "positionnednote.h"
#include <iostream>
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

void PositionnedNote::setNoteVisible(bool visible){
    note->setVisible(visible);
}

void PositionnedNote::closeEvent(QCloseEvent *event){
    note->close();
}

void PositionnedNote::paintEvent(QPaintEvent *event)
{
    note->repaint();
}
