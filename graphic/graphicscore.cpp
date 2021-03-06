#include "graphicscore.h"

GraphicScore::GraphicScore(QWidget *parent, int nb_line) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = new std::vector<PositionnedNote *>();

    this->setMinimumSize(600, 100);
    this->setMaximumSize(600, 100);

    setAcceptDrops(true);

    this->repaint();
    this->show();
}

GraphicScore::GraphicScore(QWidget *parent, int nb_line, std::vector<PositionnedNote *> *n) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = n;


    this->setMinimumSize(600, 100);
    this->setMaximumSize(600, 100);

    this->repaint();
    this->show();
}

void GraphicScore::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setBrush(QBrush(QColor(255, 230, 155)));
    painter->drawRect(0, 0, this->width(), this->height());

    //Now we trace lines
    painter->setBrush(QBrush(QColor(255, 0, 0)));
    painter->setPen(QColor(154, 0, 0));
    for(int i=0; i<nb_lines; i++)
    {
        painter->drawLine(0, this->height()/nb_lines * (i+1), this->width(), this->height()/nb_lines * (i+1));
    }

    //Finally we draw notes
    for(int i=0; i<notes->size(); i++){
        PositionnedNote *current = notes->at(i);
        current->repaint();
    }
}

void GraphicScore::dragMoveEvent(QDragMoveEvent *de)
{
    // The event needs to be accepted here
    de->accept();
}

void GraphicScore::dragEnterEvent(QDragEnterEvent *event)
{
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

void GraphicScore::dropEvent(QDropEvent *de)
{
    // Unpack dropped data and handle it the way you want
    //qDebug("Contents: %s", de->mimeData()->text().toLatin1().data());
    //QMessageBox::information(NULL, "Infos", de->mimeData()->text());
    GraphicNote *n = new GraphicNote(this, de->mimeData()->text().toInt());
    QPoint p = de->pos();
    notes->push_back(new PositionnedNote(this, n, &p));
    n->move(de->pos());
}

void GraphicScore::mousePressEvent(QMouseEvent *event)
{
    //We delete the selected note
    QWidget *child = this->childAt(event->pos());
}

