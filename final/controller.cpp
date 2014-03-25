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
}

void Controller::active()
{
    QObject::connect(frame->btn_play_pause, SIGNAL(triggered()), this, SLOT(play()));
    QObject::connect(frame->btn_record_pause, SIGNAL(triggered()), this, SLOT(record()));
    QObject::connect(frame->btn_options, SIGNAL(triggered()), this, SLOT(openConf()));
    QObject::connect(frame->btn_refresh, SIGNAL(triggered()), this,SLOT(connectToWeb()));
    QObject::connect(frame->btn_save, SIGNAL(triggered()), this, SLOT(save()));

}


void Controller::play()
{
    if(playing){
        playing = false;
        frame->btn_play_pause->setIcon(QIcon(*frame->icons_loc+"play.png"));
        partition->stopPlay();

    }else{
        playing = true;
        frame->btn_play_pause->setIcon(QIcon(*frame->icons_loc+"pause_play.png"));
        partition->startPlay();
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
//        std::cout << partition->toJSON() << std::endl;
        tablature->toTab(partition);
        frame->setTablature(tablature);
    }else{
        recording = true;
        recordThread->start();
        frame->btn_record_pause->setIcon(QIcon(*frame->icons_loc+"pause_record.png"));
    }
}

void Controller::save()
{
    saved = true;

    //We will save here the file
    std::string name = "Partition.tab";
    partition->save(name);
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

        std::cout << "CACA APRES " << std::endl;
        if(u_n && pwd){
            if((u_n->size() > 0) && (pwd->size() > 0)){

                frame->connection->connectUser(*frame->config->getUserName(), *frame->config->getPassword());

                if(frame->connection->getUserId() == -1)
                {
                    QMessageBox::information(frame, "Connexion", "Vous n'êtes pas connecté !");
                }else{
                    QMessageBox::information(frame, "Connexion", "Vous n'êtes connecté ! Votre id est : "+frame->connection->getUserId());
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
