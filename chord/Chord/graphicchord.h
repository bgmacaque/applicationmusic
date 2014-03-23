#ifndef GRAPHICCHORD_H
#define GRAPHICCHORD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QCoreApplication>
#include "graphicneedle.h"

class GraphicChord : public QWidget
{
    Q_OBJECT
    
private:

    std::vector<std::string> *notes;

    QLabel *note_label;
    GraphicNeedle *note_needle;


public:
     GraphicChord(QWidget *parent = 0);

     /*!
      * \brief setTo places the chord to the note selected
      */
     void setTo(std::string note, int dest_needle);
     void needleGoTo(qreal pos);
     void sleep(int ms);
     //void paintEvent(QPaintEvent *event);

};

#endif // GRAPHICCHORD_H
