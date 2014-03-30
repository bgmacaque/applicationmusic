#ifndef GRAPHICCHORD_H
#define GRAPHICCHORD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QCoreApplication>
#include <iostream>
#include "graphicneedle.h"

class GraphicChord : public QWidget
{
    Q_OBJECT
    
private:

    QLabel *note_label;
    GraphicNeedle *note_needle;
    int status;

    void goToLeft();
    void goToRight();
    void goAndStay();
    void needleGoTo(int pos);

public:
     GraphicChord(QWidget *parent = 0, QString first_note = "A");

     /*!
      * \brief setTo places the chord to the note selected
      */
     void setTo(std::string note, int dest_needle);
     static void sleep(int ms);
};

#endif // GRAPHICCHORD_H
