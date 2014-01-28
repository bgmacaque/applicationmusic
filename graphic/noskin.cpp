#include "NoSkin.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>

NoSkin::NoSkin(Partition *p): QMainWindow()
{
    //Locations of the icons
    std::string s = "../Images/Icons/";

    //Firstly we create all buttons
    this->loadIcons();

    //Then we create other stuff
    //analyzer = new Analyze();
    partition = p;

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);

    QList<QAction *> btn = this->getButtons();
    barre = new QMenuBar(this);
    for(int i=0; i<btn.size(); i++)
        barre->addAction(btn.at(i));

    this->setMenuBar(barre);

    //Finally, we define the window parameters
    this->setFixedSize(900, 500);
    this->setLayout(main_lay);
    this->show();
}

NoSkin::NoSkin() : QMainWindow()
{
    //Firstly we create all buttons
    this->loadIcons();

    //Then we create other stuff
    // analyzer = new Analyze();

    //partition = new Partition;

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);

    QList<QAction *> btn = this->getButtons();
    barre = new QMenuBar(this);
    for(int i=0; i<btn.size(); i++)
        barre->addAction(btn.at(i));

    this->setMenuBar(barre);

    //Finally, we define the window parameters
    //this->setFixedSize(900, 500);
    this->setLayout(main_lay);
    this->show();
}

void NoSkin::loadIcons()
{
    //Locations of the icons
    QString s("../Images/Icons/");

    btn_save = new QAction(QIcon(s + QString("save.jpg")), "", this);
    btn_import = new QAction(QIcon(s+QString("import.png")), "", this);
    btn_export = new QAction(QIcon(s+QString("export.png")), "", this);
    btn_refresh = new QAction(QIcon(s+QString("refresh.png")), "", this);
    btn_cloud_list = new QAction(QIcon(s+QString("cloud.png")), "", this);
    btn_stop = new QAction(QIcon(s+QString("stop.png")), "", this);
    btn_record_pause = new QAction(QIcon(s+QString("record.png")), "", this);
    btn_options = new QAction(QIcon(s+QString("options.png")), "", this);

    btn_play_pause = new QAction(QIcon(s), "", this);
    btn_chord = new QAction(QString("Chord"), this);
}

QList<QAction *> NoSkin::getButtons()
{
    QList<QAction *> buttons;

    buttons.append(btn_play_pause);
    buttons.append(btn_stop);
    buttons.append(btn_record_pause);
    buttons.append(btn_chord);
    buttons.append(btn_save);
    buttons.append(btn_import);
    buttons.append(btn_export);
    buttons.append(btn_refresh);
    buttons.append(btn_cloud_list);
    buttons.append(btn_options);

    return buttons;
}
