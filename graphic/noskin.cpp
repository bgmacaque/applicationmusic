#include "noskin.h"

NoSkin::NoSkin(Partition *p, int minWidth = 600, int minHeight = 200): QMainWindow()
{
    NoSkin(minWidth, minHeight);
    score = p;
}

NoSkin::NoSkin(int minWidth = 600, int minHeight = 200) : QMainWindow()
{
    //Firstly we create all buttons
    this->loadIcons();

    //Then we create other stuff
    // analyzer = new Analyze();

    //score = new Partition;

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);

    //We add the toolbar
    bar = new QToolBar("Toolbar", this);
    loadButtons();
    this->addToolBar(bar);

    //We add the right bar
    //main_lay->addLayout(this->noteModifier());

    //Finally, we define the window parameters
    this->setMinimumSize(QSize(minWidth, minHeight));
    this->setLayout(main_lay);
    this->show();
}

void NoSkin::loadIcons()
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

void NoSkin::loadButtons()
{
    bar->addAction(btn_play_pause);
    bar->addAction(btn_stop);
    bar->addSeparator();

    bar->addAction(btn_record_pause);
    bar->addSeparator();

    bar->addAction(btn_chord);
    bar->addSeparator();

    bar->addAction(btn_save);
    bar->addAction(btn_import);
    bar->addAction(btn_export);
    bar->addAction(btn_refresh);
    bar->addAction(btn_cloud_list);
    bar->addSeparator();

    bar->addAction(btn_options);
}

QVBoxLayout* NoSkin::noteModifier()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Modifier la note");

    QComboBox *box = new QComboBox(this);
    box->addItem("LA");

    layout->addWidget(label);
    layout->addWidget(box);

    return layout;
}
