#include "graphicchord.h"

GraphicChord::GraphicChord(QWidget *parent, QString first_note) : QWidget(parent)
{
    //At the beginning, the needle is at the middle
    status = 0;

    note_needle = new GraphicNeedle(this, 300, 150);
    note_label = new QLabel();

    note_label->setMinimumSize(50, 50);
    note_label->setMaximumSize(50, 50);
    note_label->setFont(QFont("Times", 30, QFont::Bold));
    note_label->setText(first_note);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(note_needle);
    lay->addWidget(note_label, 0, Qt::AlignCenter);

    this->setLayout(lay);
    this->show();

    note_needle->repaint();
    note_label->repaint();
}

void GraphicChord::setTo(QString note, int dest_needle)
{
    //We change the note displayed
    note_label->setText(note);

    //We set the needle to the new position
    needleGoTo(dest_needle);
}

void GraphicChord::needleGoTo(int pos)
{
    switch (status){
    case -1:
        switch(pos){
        case -1:
            goAndStay();
            break;
        case 0:
            goToRight();
            status = 0;
            break;
        case 1:
            goToRight();
            goToRight();
            status = 1;
            break;
        }
        break;

    case 0:
        switch(pos){
        case -1:
            goToLeft();
            status = -1;
            break;
        case 0:
            goAndStay();
            break;
        case 1:
            goToRight();
            status = 1;
            break;
        }
        break;

    case 1:
        switch(pos){
        case -1:
            goToLeft();
            goToLeft();
            status = -1;
            break;
        case 0:
            goToLeft();
            status = 0;
            break;
        case 1:
            goAndStay();
            break;
        }
        break;
    }
}

void GraphicChord::goToRight(){
    qreal ang = note_needle->getAngle();

    while(note_needle->getAngle() < (ang-1.52) || note_needle->getAngle() > (ang-1.48)){
        note_needle->goRight();
        note_needle->update();
        sleep(TEMPS_PAUSE);
    }
}

void GraphicChord::goToLeft(){
    qreal ang = note_needle->getAngle();

    while(note_needle->getAngle() < (ang+1.48) || note_needle->getAngle() > (ang+1.52)){
        note_needle->goLeft();
        note_needle->update();
        sleep(TEMPS_PAUSE);
    }
}

void GraphicChord::goAndStay(){
     for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            note_needle->goRight();
            note_needle->update();
            sleep(TEMPS_PAUSE * 5);
        }
        for(int j=0; j<3; j++){
            note_needle->goLeft();
            note_needle->update();
            sleep(TEMPS_PAUSE * 5);
        }
    }
}


#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void GraphicChord::sleep(int ms)
{
        QTime dieTime= QTime::currentTime().addMSecs(ms);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
