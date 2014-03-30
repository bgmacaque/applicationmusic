#include "graphictuner.h"

GraphicTuner::GraphicTuner(QWidget *parent, QString first_note) : QWidget(parent)
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

void GraphicTuner::setTo(QString note, int dest_needle)
{
    //We change the note displayed
    note_label->setText(note);

    //We set the needle to the new position
    needleGoTo(dest_needle);
}

void GraphicTuner::needleGoTo(int pos)
{
    //We verify the position where we are
    switch (status){
    case -1:
        //We move in function the position we want to go
        switch(pos){
        case -1:
            //We are at the same position, we just move a little
            goAndStay();
            break;
        case 0:
            //We turn one time on the right
            goToRight();
            //We change the status of the needle
            status = 0;
            break;
        case 1:
            //We turn to time to the right
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

void GraphicTuner::goToRight(){
    //We get the current angle
    qreal ang = note_needle->getAngle();

    //We turn of about 45°, that's to say about 1.50 radian
    while(note_needle->getAngle() < (ang-1.52) || note_needle->getAngle() > (ang-1.48)){
        //We turn of 0.01 radians to the right
        note_needle->goRight();

        //We refresh the display
        note_needle->update();

        //We take a little nap, because we love sleeping <3
        sleep(TEMPS_PAUSE);
    }
}

void GraphicTuner::goToLeft(){
    //We get the current angle
    qreal ang = note_needle->getAngle();

    //We turn of about 45°, that's to say about 1.50 radian
    while(note_needle->getAngle() < (ang+1.48) || note_needle->getAngle() > (ang+1.52)){
        //We turn of 0.01 radians to the left
        note_needle->goLeft();

        //We refresh the display
        note_needle->update();

        //We take a little nap, because we love sleeping <3
        sleep(TEMPS_PAUSE);
    }
}

void GraphicTuner::goAndStay(){
    /*We move a little to the right, then we move a little to the left and we repeat that*/
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

void GraphicTuner::sleep(int ms)
{
        //We compute the time when the application must go again
        QTime dieTime= QTime::currentTime().addMSecs(ms);

        //While we are  ot to this time, we put the process to sleep
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
