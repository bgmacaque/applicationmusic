#include "tabchooser.h"

TabChooser::TabChooser(NoSkin *parent, int width = 200, int height = 600)
{
    this->setMaximumSize(width, height);
    this->setMinimumSize(width, height);
    this->setParent(parent);

    //We create the partition list view
    partList = new QStringList();
    partModel = new QStringListModel(*partList, this);
    partView = new QListView(this);
    partView->setFixedSize(200, 200);
    partView->setModel(partModel);
    partView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget();

    this->setLayout(layout);
    this->show();
}

TabChooser::downloadAll()
{
    //We download th partition of all PartResume by calling their method download()
}

DBConnection* TabChooser::connection()
{
    return this->parent->getConnection();
}

Configuration* TabChooser::conf()
{
    return this->parent->getConf();
}
