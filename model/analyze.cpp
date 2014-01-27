#include "analyze.h"
#define SPECTRUM_SIZE 8192


Analyze::Analyze(){
    Note *n = new Note("A4", 440);
    this->notes.push_back(*n);
}


void Analyze::showNote(FMOD::Channel *channel){
    bool tune = true;
    float spectrum[SPECTRUM_SIZE];
    int result;
    while(tune){
        result = channel->getSpectrum(spectrum,SPECTRUM_SIZE,0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
        this->sort(spectrum);

    }
}

void Analyze::sort(float spectrum[]){

}

Note Analyze::getNote(int frequency){

}
