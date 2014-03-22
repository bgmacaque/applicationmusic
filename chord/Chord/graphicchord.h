#ifndef GRAPHICCHORD_H
#define GRAPHICCHORD_H

#include <QWidget>
#include <QLabel>

class GraphicChord : public QWidget
{
    Q_OBJECT
    
private:

    std::vector<std::string> *notes;

    QLabel *note_label;


public:
     GraphicChord(QWidget *parent = 0);

     /*!
      * \brief setTo places the chord to the note selected
      */
     void setTo(std::string note);

};

#endif // GRAPHICCHORD_H
