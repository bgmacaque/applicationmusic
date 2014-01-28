#include "NoSkin.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

NoSkin::NoSkin(Partition *p): QWidget()
{
    //Locations of the icons
    String s = "../Images/Icons/";

    //Firstly we create all buttons
    this->loadIcons();

    //Then we create other stuff
    analyzer = new Analyze();
    partition = p;

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);
    QHBoxLayout *buttons_lay = new QHBoxLayout(this);

    std::vector<QAction> btn = this->getButtons();
    for(QAction& bt : btn)
    {
        buttons_lay->addWidget(&bt);
    }

    main_lay->addLayout(buttons_lay);

    //Finally, we define the window parameters
    this->setFixedSize(900, 500);
    this->setLayout(main_lay);
    this->show();
}

NoSkin::NoSkin() : QWidget()
{
    //Locations of the icons
    String s = "../Images/Icons/";

    //Firstly we create all buttons
    this->loadIcons();

    //Then we create other stuff
    analyzer = new Analyze();
    partition = new Partition();

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);
    QHBoxLayout *buttons_lay = new QHBoxLayout(this);

    std::vector<QAction> btn = this->getButtons();
    for(QAction& bt : btn)
    {
        buttons_lay->addWidget(&bt);
    }

    main_lay->addLayout(buttons_lay);

    //Finally, we define the window parameters
    this->setFixedSize(900, 500);
    this->setLayout(main_lay);
    this->show();
}

NoSkin::loadIcons()
{
    btn_save = new QAction(QIcon(s+"save.jpg"));
    btn_import = new QAction(QIcon(s+"import.png"));
    btn_export = new QAction(QIcon(s+"export.png"));
    btn_refresh = new QAction(QIcon(s+"refresh.png"));
    btn_cloud_list = new QAction(QIcon(s+"cloud.png"));
    btn_stop = new QAction(QIcon(s+"stop.png"));
    btn_record_pause = new QAction(QIcon(s+"record.png"));
    btn_options = new QAction(QIcon(s+"options.png"));

    btn_play_pause = new QAction(QIcon(s+""));
    btn_chord = new QAction("Chord");
}

NoSkin::getButtons()
{
    std::vector<QAction> buttons;

    buttons.push_back(btn_play_pause);
    buttons.push_back(btn_stop);
    buttons.push_back(btn_record_pause);
    buttons.push_back(btn_chord);
    buttons.push_back(btn_save);
    buttons.push_back(btn_import);
    buttons.push_back(btn_export);
    buttons.push_back(btn_refresh);
    buttons.push_back(btn_cloud_list);
    buttons.push_back(btn_options);

    return buttons;
}
