#include "graphicchord.h"

GraphicChord::GraphicChord(QWidget *parent) : QWidget(parent)
{
    note_needle = new GraphicNeedle(this);
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
    while(note_needle->posX()!=pos){

        //We modify the position of the needle
        if(note_needle->posX() < pos)
            note_needle->goForward();
        else
            note_needle->goBack();

        note_needle->update();
        sleep(5);

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
