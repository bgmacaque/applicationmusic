/********************************************************************************
** Form generated from reading UI file 'graphicchord.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICCHORD_H
#define UI_GRAPHICCHORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicChord
{
public:

    void setupUi(QWidget *GraphicChord)
    {
        if (GraphicChord->objectName().isEmpty())
            GraphicChord->setObjectName(QStringLiteral("GraphicChord"));
        GraphicChord->resize(400, 300);

        retranslateUi(GraphicChord);

        QMetaObject::connectSlotsByName(GraphicChord);
    } // setupUi

    void retranslateUi(QWidget *GraphicChord)
    {
        GraphicChord->setWindowTitle(QApplication::translate("GraphicChord", "GraphicChord", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicChord: public Ui_GraphicChord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICCHORD_H
