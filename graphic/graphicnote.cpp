#include "graphicnote.h"

GraphicNote::GraphicNote(QWidget *parent, int num) : QWidget(parent), number(num)
{
    this->setMinimumSize(35, 25);
    this->setMaximumSize(35, 25);
    this->repaint();
    this->show();
}

void GraphicNote::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    //We begin by drawing the ellipse
    QBrush *background = new QBrush(QColor(23, 23, 34));
    painter->setBrush(*background);
    painter->setPen(Qt::black);
    painter->drawEllipse(0, 0, this->width()-10, this->height()-10);

    //Then we draw the number inside
    background = new QBrush(QColor(255, 255, 255));
    painter->setBrush(*background);
    painter->setPen(Qt::white);

    //On transforme le int en string
    // créer un flux de sortie
    std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << number;
    // récupérer une chaîne de caractères
    std::string chiffre = oss.str();

    if(chiffre.size() == 1)
        painter->drawText(QRect((this->width() - 17)/2, 0, this->width()-10, this->height() - 10), QString(chiffre.c_str()));
    else
        painter->drawText(QRect((this->width() - 27)/2, 0, this->width()-10, this->height() - 10), QString(chiffre.c_str()));
}
