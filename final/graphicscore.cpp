#include "graphicscore.h"
#include <iostream>


GraphicScore::GraphicScore(QWidget *parent, int nb_line, int width, int height) : QWidget(parent)
{
    nb_lines = nb_line;
    notes = new std::vector<PositionnedNote *>();
    this->setMinimumSize(width, height);
    this->setMaximumSize(width, height);
    setAcceptDrops(true);
    tabVisible = false;
    this->repaint();
    this->show();
    maxTime = 64;
    time = 0;
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

void GraphicScore::setTabVisible(bool visible){
    tabVisible = visible;
}
void GraphicScore::resizeEvent(QResizeEvent *event){
//    int currentY(0);
    QSize old = event->oldSize();
    QSize newe = event->size();
//    float newY(0);
//    float position(0);
    PositionnedNote *current(0);
    int y(0);
    int x(0);
    int posX(0);
    int posY(0);
    int oldWidth(0);
    int oldHeight(0);
    oldWidth = old.width();
    oldHeight = old.height();
    for(unsigned int i = 0 ; i < notes->size() ; i++){

        current = notes->at(i);
        x = current->getPos()->x();
        y = current->getPos()->y();
        for(unsigned int j = 0 ; j < maxTime ; j ++){
            if(oldWidth / maxTime * j == x){
                posX = newe.width() / maxTime * j;
                break;
            }
        }
        for(unsigned int j = 0 ; j < nb_lines ; j++){
            if( oldHeight - (1 + j) * oldHeight / (nb_lines + 1) - 9 == y){
                posY = newe.height() - (1 + j) * newe.height() / (nb_lines + 1) - 9;
            }
        }
        current->setPosition(new QPoint(posX, posY));
        current->repaint();

//        y = current->getPos()->y() + 9;
//        current = notes->at(i);
//        currentY = current->getPos()->y();
//        position = (float)currentY /  (float)old.height();
//        for(int j(0) ; j < nb_lines ; j++){
//            if(position >= ( ( ( (float)(j)) ) / 10) + 0.1 && position <= ( ( ( (float)(j)+1) ) / 10) + 0.1){
//                newY = (j+1) * newe.height() / (nb_lines + 1 ) - 9;
//                break;
//            }
//        }
//        if(newY != 0){
//            current->setPosition(new QPoint(current->getPos()->x(), newY));
//            current->repaint();
//        }
    }
//    this->repaint();
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
            addNote(i * this->width() / 16, (j + 1) * this->height() / 7 - 9, frets[j]->getNumber());
        }
    }
}

void GraphicScore::paintEvent(QPaintEvent *event)
{
    if(tabVisible){
        QPainter *painter = new QPainter(this);
        painter->setBrush(QBrush(QColor(255, 255, 255)));
        painter->drawRect(0, 0, this->width(), this->height());


        painter->setBrush(QBrush(QColor(0, 0, 0)));
        painter->setPen(QColor(0, 0, 0));
        painter->drawLine(this->width() / 2, 0,this->width() / 2 ,this->height());


        //Drawing a rectangle
        painter->drawLine(0, 0, 0,this->height());
        painter->drawLine(0, 0, this->width(), 0);
        painter->drawLine(0, this->height() - 1, this->width(),this->height() - 1);
        painter->drawLine(this->width() - 1, 0,this->width() - 1,this->height());

        //Now we trace lines
        for(int i = 0 ; i < nb_lines ; i++){
            painter->drawLine(0,this->height()/(nb_lines+1) * (i+1),this->width(),this->height()/(nb_lines+1) * (i+1));
        }

        //Finally we draw notes
        PositionnedNote *current;
        for(unsigned int i = 0 ; i < notes->size() ; i++){
            current = notes->at(i);
            current->repaint();
        }
    }
}

int GraphicScore::getTime(){
    return time;
}

int GraphicScore::getMaxTime(){
    return maxTime;
}

void GraphicScore::addTime(int p_time){
    time += p_time;
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
    x = this->width() / maxTime * time;
    QPoint *p = new QPoint(x, y);
    notes->push_back(new PositionnedNote(this, n, p));
    n->move(*p);
}

void GraphicScore::removeNotes(){
    unsigned int i(0);
    PositionnedNote *n;
    for(i = 0 ; i < notes->size() ; i++){
        n = notes->at(i);
        n->close();
    }
    notes->clear();
}




void GraphicScore::mousePressEvent(QMouseEvent *event)
{
    //We delete the selected note
    QWidget *child = this->childAt(event->pos());
}

