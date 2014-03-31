#ifndef GRAPHICTAB_H
#define GRAPHICTAB_H
#include <vector>
#include <QWidget>
#include <QGridLayout>
#include "graphicscore.h"
#include "tablature.h"
/*!
 * \class GraphicTab graphictab.h
 * \author Valentin STERN, Vincent ALBERT, Adonis NAJIMI, Theo GERRIET
 * \version 1.0
 * \brief Represent multiple part of a tablature on the screen
 */
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
    /*!
     * \brief Scroll the visible partitions up
     */
    void scrollUp();

    /*!
     * \brief Scroll the visible partitions down
     */
    void scrollDown();

    /*!
     * \brief Remove the notes of all the tabs
     */
    void removeNotes();

    /*!
     * \brief Add a tab to the display
     */
    void addTablature(Tablature *tab);

    /*!
     * \brief Set the tab displayed
     */
    void setTablature(Tablature *tab);
    void resizeEvent(QResizeEvent *event);
    GraphicScore *newGraphicScore();
};

#endif // GRAPHICTAB_H
