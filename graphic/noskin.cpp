#include "noskin.h"

NoSkin::NoSkin(Partition *p, int minWidth = 600, int minHeight = 200): QMainWindow()
{
    NoSkin(minWidth, minHeight);
    score = p;
}

NoSkin::NoSkin(int minWidth = 600, int minHeight = 200) : QMainWindow()
{
    //Then we create other stuff
    // analyzer = new Analyze();

    //score = new Partition;

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);

    //We add the toolbar
    bar = this->createTopBar();
    this->addToolBar(bar);

    //We add the right bar
    //main_lay->addLayout(this->noteModifier());

    //Finally, we define the window parameters
    this->setMinimumSize(QSize(minWidth, minHeight));
    this->setLayout(main_lay);
    this->show();
}

QToolBar* NoSkin::createTopBar()
{
    icons_loc = new QString("../Images/Icons/");
    this->loadTopIcons();

    QToolBar *tools = new QToolBar("Top toolbar", this);

    tools->addAction(btn_play_pause);
    tools->addAction(btn_stop);
    tools->addSeparator();

    tools->addAction(btn_record_pause);
    tools->addSeparator();

    tools->addAction(btn_chord);
    tools->addSeparator();

    tools->addAction(btn_save);
    tools->addAction(btn_import);
    tools->addAction(btn_export);
    tools->addAction(btn_refresh);
    tools->addAction(btn_cloud_list);
    tools->addSeparator();

    tools->addAction(btn_options);

    return tools;
}

void NoSkin::loadTopIcons()
{
    btn_save = new QAction(QIcon(*icons_loc+QString("save.png")), "", this);
    btn_import = new QAction(QIcon(*icons_loc+QString("import.png")), "", this);
    btn_export = new QAction(QIcon(*icons_loc+QString("export.png")), "", this);
    btn_refresh = new QAction(QIcon(*icons_loc+QString("refresh.png")), "", this);
    btn_cloud_list = new QAction(QIcon(*icons_loc+QString("cloud.png")), "", this);
    btn_stop = new QAction(QIcon(*icons_loc+QString("stop.png")), "", this);
    btn_record_pause = new QAction(QIcon(*icons_loc+QString("record.png")), "", this);
    btn_options = new QAction(QIcon(*icons_loc+QString("options.png")), "", this);

    btn_play_pause = new QAction(QIcon(*icons_loc+"play.png"), "", this);
    btn_chord = new QAction(QString("Chord"), this);
}

void NoSkin::loadBottomIcons()
{

}
