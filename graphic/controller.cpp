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
