#ifndef TABCHOOSER_H
#define TABCHOOSER_H

#include <QList>
#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QPushButton>

#include "partresume.h"
#include "../../final/configuration.h"
#include "../../final/dbconnection.h"
#include "../../final/noskin.h"

class TabChooser : QWidget
{
    Q_OBJECT

private:
    NoSkin *parent;

    QStringList *partList;
    QListView *partModel;
    QStringListModel *partView;

    QPushButton *downloadAll;

public:
    TabChooser(NoSkin *parent, int width, int height);

    /*!
     * \brief downloadAll
     * Download all partitions of the user
     */
    void downloadAll();

    /*!
     * \brief conf
     * \return  The configuration of the window
     */
    Configuration conf();

    /*!
     * \brief connection
     * \return The connection of the window
     */
    DBConnection connection();

};

#endif // TABCHOOSER_H
