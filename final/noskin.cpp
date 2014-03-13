#include "noskin.h"

/*NoSkin::NoSkin(Partition *p, int minWidth = 600, int minHeight = 200): QMainWindow()
{
    NoSkin(minWidth, minHeight);
    score = p;
}*/

NoSkin::NoSkin(int minWidth = 600, int minHeight = 200) : QMainWindow()
{
    //Then we create other stuff
    ///analyzer = new Analyze;
    ///score = new Partition;
    connection = new DBConnection("../database.conf");
    config = new Configuration();

    //We tried to load previous configs if they exist
    config->load();

    icons_loc = new QString("../Images/Icons/");

    //Now we set layout
    QVBoxLayout *main_lay = new QVBoxLayout(this);

    //We add toolbars
    topBar = this->createTopBar();
    this->addToolBar(topBar);

    g_score = new GraphicScore(this, 5);

    bottomBar = this->createBottomBar();
    this->addToolBar(Qt::BottomToolBarArea, bottomBar);

    //Finally, we define the window parameters
    this->setMinimumSize(QSize(minWidth, minHeight));
    this->setCentralWidget(g_score);
    this->show();
}

void NoSkin::setTablature(Tablature *t){
    g_score->addTablature(t);
}



QToolBar* NoSkin::createTopBar()
{
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
    tools->setStyleSheet("QToolBar {background-color : #dcdcdc;} ");
    tools->setMovable(false);

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
    btn_delete = new QAction(QIcon(*icons_loc+QString("delete.png")), "", this);
    btn_new = new QAction(QIcon(*icons_loc+QString("new.png")), "", this);
    btn_forward = new QAction(QIcon(*icons_loc+QString("forward_arrow.png")), "", this);
    btn_back = new QAction(QIcon(*icons_loc+QString("back_arrow.png")), "", this);
    choice_name = new QLineEdit(this);
    choice_difficulty = new QComboBox(this);
    choice_tempo = new QSpinBox(this);
}

QToolBar* NoSkin::createBottomBar()
{
    this->loadBottomIcons();

    QToolBar *bottom = new QToolBar("bottom", this);
    QVBoxLayout *lay = new QVBoxLayout;
    QWidget* tmp = new QWidget;

    bottom->addAction(btn_delete);
    bottom->addAction(btn_new);
    bottom->addAction(btn_back);
    bottom->addAction(btn_forward);

    bottom->addSeparator();

    lay->addWidget(choice_name);
    lay->addWidget(choice_difficulty);
    lay->addWidget(choice_tempo);
    lay->addWidget(new GraphicNote(NULL, 5));

    choice_name->setPlaceholderText(QString("Nom de la partition"));

    choice_difficulty->setMaximumWidth(150);
    choice_name->setMaximumWidth(150);
    choice_tempo->setMaximumWidth(150);

    choice_difficulty->addItem("Facile");
    choice_difficulty->addItem("Normal");
    choice_difficulty->addItem("Difficile");
    choice_difficulty->addItem("Maxi-Hardcore");

    tmp->setLayout(lay);

    bottom->addWidget(tmp);

//    bottom->addWidget(choice_name);
//    bottom->addWidget(choice_tempo);
//    bottom->addWidget(choice_difficulty);

    bottom->setMovable(false);
    bottom->setStyleSheet("QToolBar {background-color : #dcdcdc;} ");

    return bottom;
}

Configuration* NoSkin::getConf()
{
    return this->config;
}

void NoSkin::reloadConf()
{
    this->config = new Configuration();
    this->config->load();
}
