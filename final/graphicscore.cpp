#include "graphicscore.h"
#include <iostream>


GraphicScore::GraphicScore(QWidget *parent, int nb_line, int width, int height) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = new std::vector<PositionnedNote *>();

    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
    setAcceptDrops(true);

    this->repaint();
    this->show();
}

//GraphicScore::GraphicScore(QWidget *parent, int nb_line, std::vector<PositionnedNote *> *n) : QWidget(parent)
//{
//    nb_lines = nb_line;
//    notes = n;


//    this->setMinimumSize(600, 120);
//    this->setMaximumSize(600, 120);

//    this->repaint();
//    this->show();
//}

void GraphicScore::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(0, 0, this->width(), this->height());

    //Now we trace lines
    painter->setBrush(QBrush(QColor(255, 0, 0)));
    painter->setPen(QColor(0, 0, 0));
    for(int i=0; i<nb_lines; i++)
    {
        painter->drawLine(0, this->height()/(nb_lines+1) * (i+1), this->width(), this->height()/(nb_lines+1) * (i+1));
    }

    //Finally we draw notes
    for(unsigned int i = 0 ; i < notes->size() ; i++){
        PositionnedNote *current = notes->at(i);
        current->repaint();
    }
}


void GraphicScore::resizeEvent(QResizeEvent *event){
    int currentY(0);
    QSize old = event->oldSize();
    QSize newe = event->size();
    float divY(0);
    divY = (float)old.height() / (float)newe.height();
    float newY(0);
    float position(0);
    PositionnedNote *current(0);
    for(unsigned int i = 0 ; i < notes->size() ; i++){
        current = notes->at(i);
        currentY = current->getPos()->y();
        position = (float)currentY /  (float)old.height();
        //Repositionnement de la note
        for(int j(0) ; j < nb_lines ; j++){
            if(position >= (j) / 10 + 0.01 && position <= (j+1) + (j+1) / 10 + 0.01){
                std::cout << position << std::endl;
                newY = (j+1) * newe.height() / 7 - 9;
                break;
            }
        }
        if(newY == 0){
            newY = 1;
        }
        current->setPosition(new QPoint(current->getPos()->x(), newY));
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
    int x = de->pos().x();
    int y = de->pos().y();
    this->addNote(x, y, de->mimeData()->text().toInt());
}

void GraphicScore::addNote(int x, int y, int number){
    GraphicNote *n = new GraphicNote(this, number);
    QPoint *p = new QPoint(x, y);
    notes->push_back(new PositionnedNote(this, n, p));
    n->move(*p);
}

void GraphicScore::addTablature(Tablature *t){
    std::vector<FrettedChord*> tabFrets = t->getFrets();
    int unsigned i(0);
    int j(0);
    FrettedChord *fc;
    Fret **frets;
    for(i = 0 ; i < tabFrets.size() ; i++){
        fc = tabFrets.at(i);
        frets = fc->getFrets();
        for(j = 0 ; j < fc->getNumberFrets() ; j++){
            std::cout << this->height() << std::endl;
            addNote(i * this->width() / 16, (j + 1) * this->height() / 7 - 9, frets[j]->getNumber());
        }
    }
}



void GraphicScore::mousePressEvent(QMouseEvent *event)
{
    //We delete the selected note
    QWidget *child = this->childAt(event->pos());
}

