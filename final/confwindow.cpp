#include "confwindow.h"

ConfWindow::ConfWindow(NoSkin* parent):QMainWindow()
{
    this->parent = parent;
    pages = new QStackedWidget(this);
    tabs = new QToolBar("Nav");
    tabs->setMovable(false);
    tabs->setStyleSheet("QToolBar {background-color : #dcdcdc;} ");

    this->loadTabs();

    btn_apply = new QPushButton("Appliquer");

    //We load all pages
    loadAuthPage();
    loadOptionsPage();
    loadSkinsPage();

    link();
    this->addToolBar(Qt::LeftToolBarArea, tabs);

    this->setCentralWidget(pages);
    pages->setCurrentWidget(page_connection);

    //We laod preexisting configs
    parent->config = new Configuration();
    if(parent->config->load())
    {
        this->setConfig();
    }

    this->setWindowTitle(QString("Configuration - Authentification"));
    this->show();
}

void ConfWindow::loadTabs()
{
    btn_connection = new QAction(QIcon(*this->parent->icons_loc+"key.png"),"", this);
    btn_options = new QAction(QIcon(*this->parent->icons_loc+"note.png"),"", this);
    btn_skins = new QAction(QIcon(*this->parent->icons_loc+"skin.png"),"", this);

    tabs->addAction(btn_connection);
    tabs->addAction(btn_options);
    tabs->addAction(btn_skins);
}

void ConfWindow::loadAuthPage()
{
    this->page_connection = new QWidget(this);
    page_connection->setObjectName("page_connection");

    layout_connection = new QFormLayout(this);

    username = new QLineEdit();
    password = new QLineEdit();

    password->setEchoMode(QLineEdit::Password);

    pass_saved = new QCheckBox(this);
    login_at_start = new QCheckBox(this);
    relogin_after_errors = new QCheckBox(this);

    reloging_after = new QSpinBox(this);
    reloging_after->setMinimum(1);
    reloging_after->setMaximum(60);

    layout_connection->addRow("Nom d'utilisateur ",username);
    layout_connection->addRow("Mot de passe ", password);
    layout_connection->addRow("Sauver votre mot de passe", pass_saved);
    layout_connection->addRow("Vous connecter au lancement", login_at_start);
    layout_connection->addRow("Vous reconnecter après erreur", relogin_after_errors);
    layout_connection->addRow("Vous reconnecter après", reloging_after);
    layout_connection->addWidget(btn_apply);

    page_connection->setLayout(layout_connection);
    this->pages->addWidget(page_connection);
}

void ConfWindow::loadOptionsPage()
{
    this->page_options = new QWidget(this);
    page_options->setObjectName("page_options");

    this->pages->addWidget(page_options);
}

void ConfWindow::loadSkinsPage()
{
    this->page_skins = new QWidget(this);
    page_skins->setObjectName("page_skins");

    this->pages->addWidget(page_skins);
}

void ConfWindow::link()
{
    QObject::connect(btn_connection, SIGNAL(triggered()), this, SLOT(setAuthPage()));
    QObject::connect(btn_options, SIGNAL(triggered()), this, SLOT(setOptionsPage()));
    QObject::connect(btn_skins, SIGNAL(triggered()), this, SLOT(setSkinsPage()));
    QObject::connect(btn_apply, SIGNAL(clicked()), this, SLOT(apply()));
    QObject::connect(relogin_after_errors, SIGNAL(clicked(bool)), this, SLOT(activeRelogTime(bool)));
    QObject::connect(username, SIGNAL(textChanged(QString)), this, SLOT(activeAll()));
    QObject::connect(password, SIGNAL(textChanged(QString)), this, SLOT(activeSavePass()));
}


//SLOTS
void ConfWindow::setAuthPage()
{
    this->setWindowTitle("Configuration - Authentification");
    pages->setCurrentWidget(page_connection);
}

void ConfWindow::setOptionsPage()
{
    this->setWindowTitle("Configuration - Music options");
    pages->setCurrentWidget(page_options);
}

void ConfWindow::setSkinsPage()
{
    this->setWindowTitle("Configuration - Skins");
    pages->setCurrentWidget(page_skins);
}

void ConfWindow::apply()
{
    Configuration *c;
    if(!username->text().isEmpty())
        c = new Configuration(username->text(), password->text(), pass_saved->isChecked(), login_at_start->isChecked(),relogin_after_errors->isChecked(), reloging_after->value());
    else
        c = new Configuration();

    c->save();
    parent->reloadConf();

    this->close();
}

void ConfWindow::setConfig()
{
    username->setText(*parent->config->getUserName());
    if(!activeAll())
    {
        password->setText(*parent->config->getPassword());
        login_at_start->setChecked(parent->config->getLogAtStart());
        reloging_after->setValue(parent->config->getRelogingAfter());
        relogin_after_errors->setChecked(parent->config->getRelogingAfterError());
        if(activeSavePass())
            pass_saved->setChecked(parent->config->getPasswordSaved());
        else
            pass_saved->setChecked(false);
    }
}

void ConfWindow::activeRelogTime(bool activated)
{
    this->reloging_after->setEnabled(activated);
}

bool ConfWindow::activeAll()
{
        bool disabled = username->text().isEmpty();

        password->setDisabled(disabled);
        activeSavePass();
        relogin_after_errors->setDisabled(disabled);
        reloging_after->setDisabled(disabled || !relogin_after_errors->isChecked());
        login_at_start->setDisabled(disabled);

        return disabled;
}

bool ConfWindow::activeSavePass()
{
    bool possible = !password->text().isEmpty();
    pass_saved->setEnabled(possible);
    pass_saved->setChecked(possible);

    return possible;
}
