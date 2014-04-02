#include "fret.h"
#include <iostream>

Fret::Fret(int p_number, Note *p_note, int p_indexString){
    m_number = p_number;
    m_note = p_note;
    m_indexString = p_indexString;
//    std::cout << m_note->getDisplay() << std::endl;
}

int Fret::getNumber() const{
    return m_number;
}

Note *Fret::getNote() const{
    return m_note;
}

int Fret::getIndexString() const{
    return m_indexString;
}

void Fret::parse(FileReader *fr){
    std::string word = fr->getCurrent();
    if(word.compare("{") != 0){
        throw "Parse error";
    }

    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("line") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
    word = fr->next();


    word = fr->next();
    if(word.compare(",") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("number") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare("\"") != 0){
        throw "Parse error";
    }
    word = fr->next();
    if(word.compare(":") != 0){
        throw "Parse error";
    }
    word = fr->next();
    word = fr->next();
    if(word.compare("}") != 0){
        throw "Parse error";
    }
}

QString Fret::stringify() const{
    QString retour = "";
    retour.append(" { ");
    retour.append(" \" line \" : ");
    retour.append(QString::number(m_indexString));
    retour.append(" , ");
    retour.append(" \" number \" : ");
    retour.append(QString::number(m_number));
    retour.append(" } ");
    return retour;
}
