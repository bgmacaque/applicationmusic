#include "graphicchord.h"

#define TEMPS_PAUSE 5

GraphicChord::GraphicChord(QWidget *parent) : QWidget(parent)
{
    status = 0;

    note_needle = new GraphicNeedle(this, 300, 150);
    note_label = new QLabel();

    note_label->setMinimumSize(50, 50);
    note_label->setMaximumSize(50, 50);
    note_label->setFont(QFont("Times", 30, QFont::Bold));
    note_label->setText("B");

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(note_needle);
    lay->addWidget(note_label, 0, Qt::AlignCenter);

    this->setLayout(lay);


    this->show();

    note_needle->repaint();
    note_label->repaint();
}

void GraphicChord::setTo(std::string note, int dest_needle)
{
    note_label->setText(QString(note.c_str()));
    needleGoTo(dest_needle);
}

void GraphicChord::needleGoTo(int pos)
{
    /*int posXIni = note_needle->x();
    int posYIni = note_needle->y();

    int posX = note_needle->width()/2;
    int posY = 20;

    if(pos == 1){
        posX = note_needle->width() - 30;
        posY = note_needle->height() - 30;
    }else if(pos==-1){
        posX = 30;
        posY = note_needle->height() - 30;
        std::cout << "COUCOU" << posX << "  :  " << posY << std::endl;
    }

    bool end = false;

    while(note_needle->y()!=posY && note_needle->x()!=posX && !end){

        //We modify the position of the needle
        if(posXIni > posX){
            //if(note_needle->y()<=note_needle->height())
                note_needle->goLeft();

                if(note_needle->x() < posX){
                    end = true;
                }
        }else if(posXIni < posX ){

            //if(note_needle->y()<=note_needle->height())
                note_needle->goRight();

            if(note_needle->x() > posX){
                end = true;
            }
        }

        note_needle->update();
        sleep(50);
    }

    std::cout << "Aim : x-> " << posX << "  y-> " << posY<< std::endl;
    std::cout << "FIN : x-> " << note_needle->x() << "  y-> " << note_needle->y() << std::endl;

    //if(posX)*/
    std::cout << status << std::endl;
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
        std::cout << "ANGLE PREVU : " << ang-1.48 << ", ANGLE COURANT : " << note_needle->getAngle();
        note_needle->goRight();
        note_needle->update();
        sleep(TEMPS_PAUSE);
    }

    /*if(note_needle->getAngle() < 0.4){
        note_needle->setAngle(0.4);
    }*/
}

void GraphicChord::goToLeft(){
    /*for(int i=0; i<NB_TOURS_ROTATION; i++){
        note_needle->goRight();
        note_needle->update();
        sleep(TEMPS_PAUSE);

        //std::cout << note_needle->getAngle() << std::endl;

        if(note_needle->getAngle() > 2.8){
            note_needle->setAngle(2.8);
            break;
        }
    }*/
    qreal ang = note_needle->getAngle();
    while(note_needle->getAngle() < (ang+1.48) || note_needle->getAngle() > (ang+1.52)){
        note_needle->goLeft();
        note_needle->update();
        sleep(TEMPS_PAUSE);
    }

    /*if(note_needle->getAngle() > 2.8){
        note_needle->setAngle(2.8);
    }*/
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
