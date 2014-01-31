#include "confwindow.h"

ConfWindow::ConfWindow(NoSkin* parent):QMainWindow()
{
    this->parent = parent;
    pages = new QStackedWidget(this);
    tabs = new QToolBar("Nav");
    tabs->setMovable(false);

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
    config = new Configuration();
    if(config->load())
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
    config = new Configuration(username->text(), password->text(), pass_saved->isChecked(), relogin_after_errors->isChecked(), reloging_after->value());
    config->save();
    this->close();
}

void ConfWindow::setConfig()
{
    username->setText(*config->getUserName());
    password->setText(*config->getDecryptedPass());
    reloging_after->setValue(config->getRelogingAfter());
    relogin_after_errors->setChecked(config->getRelogingAfterError());
    pass_saved->setChecked(config->getPasswordSaved());
}

void ConfWindow::activeRelogTime(bool activated)
{
    this->reloging_after->setEnabled(activated);
}
