#include "graphicchord.h"
#include "ui_graphicchord.h"

GraphicChord::GraphicChord(QWidget *parent) : QWidget(parent)
{

}

void GraphicChord::setTo(std::string note)
{
    note_label->setText(note);

}
