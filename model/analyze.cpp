#include "analyze.h"
#define SPECTRUM_SIZE 8192


Analyze::Analyze(){
    Note *n = new Note("A4", 440);
    this->notes.push_back(*n);
}




void Analyze::mainNote(FMOD::Channel *channel){
    bool tune = true;
    float spectrum[SPECTRUM_SIZE];
    int result;
    while(tune){
        result = channel->getSpectrum(spectrum,SPECTRUM_SIZE,0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
//        this->sort(spectrum, SPECTRUM_SIZE, 0, SPECTRUM_SIZE - 1);
    }
}

void Analyze::sort(int places[], float spectrum[], int size, int inf, int sup){
    int index;
    if(inf < sup){
        index = (inf + sup) / 2;
        this->sort(places, spectrum, size, inf, index - 1);
        this->sort(places, spectrum, size, index + 1, sup);
    }
}

int Analyze::place(float spectrum[], int size, int inf, int sup){
    int inda = inf;
    float temp;
    float a = spectrum[inf];
    inf--;
    while(sup >= inf){
        if(spectrum[inf] > a){
            while(sup >= inf || spectrum[sup] > a){
                sup--;
            }
            temp = spectrum[sup];
            spectrum[sup] = spectrum[inf];
            spectrum[inf] = temp;
            sup--;
        }
        inf--;
    }
    temp = spectrum[sup];
    spectrum[sup] = spectrum[inda];
    spectrum[inda] = temp;
}

Note Analyze::getNote(int frequency){

}
