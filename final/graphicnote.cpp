#include "graphicnote.h"
#include <iostream>
GraphicNote::GraphicNote(QWidget *p, int num) : QWidget(p), number(num)
{
    parent = p;
    this->setMinimumSize(35, 25);
    this->setMaximumSize(35, 25);
    this->repaint();
    this->show();
}

void GraphicNote::setParent(QWidget *p_parent){
    parent = p_parent;
}

void GraphicNote::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    std::cout << "COUCOU, je suis une note" << std::endl;
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

void GraphicNote::mousePressEvent(QMouseEvent *event)
{
    drager = new QDrag(this);
    QMimeData *data = new QMimeData;
    data->setText(QString::number(number));
    drager->setMimeData(data);
    QPixmap pixmap(this->size());
    this->render(&pixmap);
    drager->setPixmap(pixmap);
    drager->exec();
    setAcceptDrops(true);

    if(parent)
        delete this;
}

int GraphicNote::getNumber()
{
    return this->number;
}

QDrag* GraphicNote::getDrager()
{
    return this->drager;
}
