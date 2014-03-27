#include "graphictab.h"

GraphicTab::GraphicTab(QWidget *p_parent, unsigned int p_nbLines, int width, int height) : QWidget(p_parent)
{
    this->setMinimumSize(width, height);
    m_nbLines = p_nbLines;
    m_parent = p_parent;
    m_indexVisible = 0;

    m_scores.push_back(new GraphicScore(this, m_nbLines, this->width() / 2, (6 * this->height()) / 14));
    m_scores.push_back(new GraphicScore(this, m_nbLines, this->width() / 2, (6 * this->height()) / 14));
    m_scores.push_back(new GraphicScore(this, m_nbLines, this->width() / 2, (6 * this->height()) / 14));
    m_scores.push_back(new GraphicScore(this, m_nbLines, this->width() / 2, (6 * this->height()) / 14));
    this->scrollUp();
}

void GraphicTab::scrollUp(){
    if(m_indexVisible >= 2){
        m_indexVisible -= 2;
    }
    this->repaint();
}

void GraphicTab::scrollDown(){
    if(m_indexVisible + 2 < m_scores.size()){
        m_indexVisible += 2;
    }
    this->repaint();
}

void GraphicTab::removeNotes(){
    m_indexVisible = 0;
    unsigned int i(0);
    for(i = 0 ; i < m_scores.size() ; i++){
        m_scores.at(i)->removeNotes();
    }
}

void GraphicTab::addTablature(Tablature *tab){
    std::vector<FrettedChord*> tabFrets = tab->getFrets();
    int unsigned i(0);
    int j(0);
    FrettedChord *fc;
    Fret **frets;
    for(i = 0 ; i < tabFrets.size() ; i++){
        fc = tabFrets.at(i);
        frets = fc->getFrets();
        for(j = 0 ; j < fc->getNumberFrets() ; j++){
            m_scores[0]->addNote(i * this->width() / 16, (j + 1) * this->height() / 7 - 9, frets[j]->getNumber());
        }
    }
}

void GraphicTab::resizeEvent(QResizeEvent *event){
    unsigned int i(0);
    GraphicScore *score;
    for( i = 0 ; i < m_scores.size() ; i++){
        score = m_scores.at(i);
        score->setMaximumSize(this->width() / 2, (6 * this->height()) / 14);
        score->setMinimumSize(this->width() / 2, (6 * this->height()) / 14);
    }
}

void GraphicTab::paintEvent(QPaintEvent *event){
    unsigned int i(0);
    unsigned maxVisible = m_indexVisible + 4;
    if(m_indexVisible + 4 > m_scores.size()){
        maxVisible = m_scores.size();
    }
    GraphicScore *score;
    for(i = 0 ; i < m_scores.size() ; i ++){
        score = m_scores.at(i);
    }
    int x(0);
    int y(0);
    QPainter *painter = new QPainter(this);
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(x, y, this->width(), this->height());

    delete painter;
    for(i = m_indexVisible ; i < maxVisible ; i++){
        score = m_scores.at(i);
        if( i == m_indexVisible){
            x = 0;
            y = 0;
        }else if(i == m_indexVisible + 1){
            x = this->width() / 2;
            y = 0;
        }else if(i == m_indexVisible + 2){
            x = 0;
            y = this->height() / 2 + this->height() / 14;
        }else if(i == m_indexVisible + 3){
            x = this->width() / 2;
            y = this->height() / 2 + this->height() / 14;
        }
        score->move(x, y);
        score->setTabVisible(true);
    }
}
