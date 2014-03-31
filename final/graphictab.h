#ifndef GRAPHICTAB_H
#define GRAPHICTAB_H
#include <vector>
#include <QWidget>
#include <QGridLayout>
#include "graphicscore.h"
#include "tablature.h"

class GraphicTab : public QWidget
{
private:
    std::vector<GraphicScore *> m_scores;
    QWidget *m_parent;
    unsigned int m_indexVisible;
    unsigned int m_nbLines;
    int m_x;
    int m_y;
    int lastScore;

public:
    GraphicTab(QWidget *p_parent, unsigned int p_nbLines, int width, int height);
    void paintEvent(QPaintEvent *event);
    void scrollUp();
    void scrollDown();
    void removeNotes();
    void addTablature(Tablature *tab);
    void setTablature(Tablature *tab);
    void resizeEvent(QResizeEvent *event);
    GraphicScore *newGraphicScore();
};

#endif // GRAPHICTAB_H
