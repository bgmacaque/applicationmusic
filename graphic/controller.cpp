#include "controller.h"

Controller::Controller(NoSkin *f) : frame(f)
{
    playing = false;
    recording = false;
    saved = true;
}

void Controller::active()
{
    QObject::connect(frame->btn_play_pause, SIGNAL(triggered()), this, SLOT(play()));
    QObject::connect(frame->btn_record_pause, SIGNAL(triggered()), this, SLOT(record()));
    QObject::connect(frame->btn_options, SIGNAL(triggered()), this, SLOT(openConf()));
    QObject::connect(frame->btn_refresh, SIGNAL(triggered()), this,SLOT(connectToWeb()));
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
    }else{
        recording = true;
        frame->btn_record_pause->setIcon(QIcon(*frame->icons_loc+"pause_record.png"));
    }
}

void Controller::save()
{
    saved = true;

    //We will save here the file

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
