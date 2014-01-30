#include "confwindow.h"

ConfWindow::ConfWindow(NoSkin* parent):QMainWindow()
{
    this->parent = parent;
    pages = new QStackedWidget(this);
    tabs = new QToolBar("Nav");
    tabs->setMovable(false);

    this->loadTabs();

    main_lay = new QHBoxLayout(this);

    main_lay->addWidget(pages);
    this->addToolBar(Qt::LeftToolBarArea, tabs);

    this->setWindowTitle(QString("Configuration"));
    this->show();
}

void ConfWindow::loadTabs()
{
    btn_connection = new QAction(QIcon(*this->parent->icons_loc+"key.png"));
    btn_options = new QAction(QIcon(*this->parent->icons_loc+"note.png"));
    btn_skins = new QAction(QIcon(*this->parent->icons_loc+"skin.png"));

    tabs->addAction(btn_connection);
    tabs->addAction(btn_options);
    tabs->addAction(btn_skins);
}
