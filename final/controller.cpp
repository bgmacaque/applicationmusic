#include "controller.h"



Controller::Controller(NoSkin *f) : frame(f)
{
    playing = false;
    recording = false;
    saved = true;
    partition = new Partition(120, 0.025, 0.025);
    fmodlib = new FModInit();
    analyze = new Analyze(fmodlib->getSystem(), fmodlib->getSound());
    recordThread = new RecordThread(partition, analyze);
    frame->btn_save->setEnabled(false);
    tablature = new Tablature();
    tune_thread = new TuneThread(analyze, frame->tuner);
    tune_thread->start();
}

void Controller::scrollDown(){
    frame->g_tab->scrollDown();
}

void Controller::scrollUp(){
    frame->g_tab->scrollUp();
}

void Controller::active()
{
    QObject::connect(frame->btn_play_pause, SIGNAL(triggered()), this, SLOT(play()));
    QObject::connect(frame->btn_record_pause, SIGNAL(triggered()), this, SLOT(record()));
    QObject::connect(frame->btn_options, SIGNAL(triggered()), this, SLOT(openConf()));
    QObject::connect(frame->btn_refresh, SIGNAL(triggered()), this,SLOT(connectToWeb()));
    QObject::connect(frame->btn_save, SIGNAL(triggered()), this, SLOT(save()));
    QObject::connect(frame->btn_export, SIGNAL(triggered()), this, SLOT(upload()));
    QObject::connect(frame->choice_tempo, SIGNAL(valueChanged(int)), this, SLOT(changeTempo(int)));
    QObject::connect(frame->btn_delete, SIGNAL(triggered()), this, SLOT(deletePart()));
    QObject::connect(frame->btn_open, SIGNAL(triggered()), this, SLOT(openPartition()));
    QObject::connect(frame->btn_back, SIGNAL(triggered()), this, SLOT(scrollUp()));
    QObject::connect(frame->btn_forward, SIGNAL(triggered()), this, SLOT(scrollDown()));

}

void Controller::openPartition(){
    QString path = QFileDialog::getOpenFileName(frame, "Ouvrir une partition", QString());
    if(path.compare("") != 0){
        try{
            partition = Partition::load(path.toStdString().c_str());
            tablature = new Tablature();
            tablature->toTab(partition);
            frame->g_tab->removeNotes();
            frame->g_tab->addTablature(tablature);
            saved = true;
            frame->btn_save->setEnabled(false);
        }catch( ... ){
            std::cout << "ERROR" << std::endl;
        }
    }
}

void Controller::deletePart(){
    if(!saved){
        int response = QMessageBox::question(frame, "Sauvegarde", "Le fichier n'a pas été sauvegardé, voulez-vous le sauvegarder?",QMessageBox ::Yes | QMessageBox::No | QMessageBox::Abort);
        if(response == QMessageBox::Yes){
            if(partition->getName().compare("") == 0){
                QString path = QFileDialog::getSaveFileName(frame, "Enregistrer la partition", QString(), "Partition (*.tab)");

                QStringList list1 = path.split("/");
                partition->setName(list1.at(list1.size() - 1).toStdString());
                //We will save here the file
                partition->save(path.toStdString());
            }else{
                partition->save(partition->getPath());
            }
            saved = true;
            frame->btn_save->setEnabled(false);
            frame->g_tab->setTablature(new Tablature());
            partition->deleteChords();
        }else if(response == QMessageBox::No){
            frame->g_tab->setTablature(new Tablature());
            partition->deleteChords();
        }
    }else{

        frame->g_tab->setTablature(new Tablature());
        partition->deleteChords();
    }
    frame->g_tab->repaint();
}

void Controller::changeTempo(int tempo){
    partition->setTempo(tempo);
}

void Controller::upload(){
    if(frame->connection->getUserId() == -1 ){
        frame->connection->connectUser(*frame->getConf()->getUserName(), *frame->getConf()->getPassword());
    }
    if(frame->connection->getUserId() != -1 ){
        bool ok = true;
        while(partition->getName().compare("") == 0 && ok){
            QString partitionName = QInputDialog::getText(frame, "Upload", "Nom de la partition?", QLineEdit::Normal, QString(), &ok);
            if(ok){
                partition->setName(partitionName.toStdString());
                frame->setWindowTitle(partitionName);
            }
        }
        if(ok){
            if(frame->connection->insert(partition)){
                QMessageBox::information(frame, "Upload","Upload effectué avec succés");
            }
        }
    }else{
        QMessageBox::information(frame, "Connexion", "Vous n'êtes pas connectés!");
    }
}

void Controller::play()
{
    if(playing){
        playing = false;
        frame->btn_play_pause->setIcon(QIcon(*frame->icons_loc+"play.png"));

    }else{
        playing = true;
        frame->btn_play_pause->setIcon(QIcon(*frame->icons_loc+"pause_play.png"));
    }
}

void Controller::record()
{
    if(recording){
        recording = false;
        frame->btn_record_pause->setIcon(QIcon(*frame->icons_loc+"record.png"));
        partition = recordThread->stop();
        saved = false;
        frame->btn_save->setEnabled(true);
        delete tablature;
        tablature = new Tablature();
        tablature->toTab(partition);
        frame->g_tab->setTablature(tablature);
    }else{
        recording = true;
        recordThread->start();
        frame->btn_record_pause->setIcon(QIcon(*frame->icons_loc+"pause_record.png"));
    }
}

void Controller::save()
{

//    QString path = QFileDialog::getSaveFileName(frame, "Enregistrer la partition", "./", "");
//    QStringList list1 = path.split("/");
//    partition->setName(list1.at(list1.size() - 1).toStdString());
    //We will save here the file
    bool ok = true;
    while(partition->getName().compare("") == 0 && ok){
        QString partitionName = QInputDialog::getText(frame, "Upload", "Nom de la partition?", QLineEdit::Normal, QString(), &ok);
        if(ok){
            partition->setName(partitionName.toStdString());
            frame->setWindowTitle(partitionName);
            partition->save("./" + partitionName.toStdString());
        }
    }
//    partition->save(path.toStdString());
//    partition->setPath(path.toStdString());
//    frame->setWindowTitle(QString::fromStdString(list1.at(list1.size() - 1).toStdString()));
    saved = true;
    frame->btn_save->setEnabled(false);
}

void Controller::openConf()
{
   ConfWindow *conf_window = new ConfWindow(frame);
}

void Controller::connectToWeb()
{
    if(frame->connection)
    {
        QString *u_n = frame->getConf()->getUserName(), *pwd = frame->getConf()->getPassword();

        if(u_n && pwd){
            if((u_n->size() > 0) && (pwd->size() > 0)){

                frame->connection->connectUser(*frame->config->getUserName(), *frame->config->getPassword());
                if(frame->connection->getUserId() == -1)
                {
                    QMessageBox::information(frame, "Connexion", "Vous n'êtes pas connecté !");
                }else{
                    QMessageBox::information(frame, "Connexion", "Vous êtes connecté ! ");
                }
            }else{
                QMessageBox::information(frame, "Connexion", "Vous devez renseignez vos identifiants pour vous connecter !");
            }

        }else{
            QMessageBox::information(frame, "Connexion", "Vous devez renseignez vos identifiants pour vous connecter !");
        }
    }else{
        QMessageBox::information(frame, "Connexion", "Nous n'avons pu vous connecter à la base de données");
    }
}

Controller::~Controller(){
    delete partition;
    delete analyze;
    delete fmodlib;
    delete recordThread;
}
