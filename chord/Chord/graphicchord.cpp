#include "graphicchord.h"

GraphicChord::GraphicChord(QWidget *parent) : QWidget(parent)
{
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

void GraphicChord::needleGoTo(qreal pos)
{
    int posXIni = note_needle->x();
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
        sleep(30);
    }

    std::cout << "Aim : x-> " << posX << "  y-> " << posY<< std::endl;
    std::cout << "FIN : x-> " << note_needle->x() << "  y-> " << note_needle->y() << std::endl;

    //if(posX)
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
