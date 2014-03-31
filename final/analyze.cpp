#include "analyze.h"

#define SPECTRUM_SIZE 8192

//Juste during debug
using namespace std;




Analyze::Analyze(FMOD::System *p_system, FMOD::Sound *p_sound){
    m_system = p_system;
    m_sound = p_sound;
}

Analyze::~Analyze(){
}


void Analyze::start(){
    m_channel = 0;
    int result(0);
    result = m_system->recordStart(0, m_sound, true);
    result = m_system->playSound(FMOD_CHANNEL_REUSE, m_sound, false, &m_channel);
    result = m_channel->setVolume(0);
}


void Analyze::close(){
    m_system->recordStop(0);
}

Chord *Analyze::mainChord(int size_max, float *maxVolume){
    return this->mainChord(size_max, 0, 16000.0f, maxVolume);
}

Chord *Analyze::mainChord(int size_max, float freqMin, float freqMax, float *maxVolume){
    float spectrum[SPECTRUM_SIZE];
    int result(0), i(0);
    int *places = this->placesForSpectrum();
    result = m_channel->getSpectrum(spectrum, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
    this->sort(places, spectrum, 0, SPECTRUM_SIZE - 1);
    Chord *c = new Chord();
    Note *n = 0;
    i = SPECTRUM_SIZE - 1;
    bool stop = false;
    while(i >= 0 && c->notesNumber() < size_max && !stop){
        if(spectrum[places[i]] < 0.025){
            stop = true;
        }else{
            n = this->getNote(this->getFrequency(places[i]));
            if(!c->contains(n) && n->getFrequency() >= freqMin && n->getFrequency() <= freqMax){
                c->addNote(n);
            }
            i--;
        }
    }
    *maxVolume = spectrum[places[SPECTRUM_SIZE - 1]];
    delete[] places;
    return c;
}


void Analyze::mainNote(Note *note, float *diff){
    float spectrum[SPECTRUM_SIZE], max(0), freqMax(0);
    int result(0), i(0), indexMax(0);
    Note *n = 0;
    result = m_channel->getSpectrum(spectrum, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
    if(result != FMOD_OK){
        std::cout << "Erreur : " << result << std::endl;
    }
    max = 0;
    freqMax = 0;
    for(i = 0; i < SPECTRUM_SIZE; i++){
        if(spectrum[i] > max){
            max = spectrum[i];
            indexMax = i;
        }
    }
    cout << "Volume max " << spectrum[indexMax] << endl;
    freqMax = this->getFrequency(indexMax);
    n = getNote(freqMax, diff);
    if(n != 0){
        note->setFrequency(n->getFrequency());
        note->setName(n->getName());
    }
}

float Analyze::getFrequency(int placeInSpectrum){
    return (float)placeInSpectrum * (((float)48000 / 2.0f) / (float)SPECTRUM_SIZE);
}


int *Analyze::placesForSpectrum(){
    int *places = new int[SPECTRUM_SIZE];
    unsigned int i(0);
    for(i = 0 ; i < SPECTRUM_SIZE ; i++){
        places[i] = i;
    }
    return places;
}

void Analyze::sort(int places[], float spectrum[], int inf, int sup){
    int index(0);
    //If it's the first call
    if(inf < sup){
        index = this->place(places, spectrum, inf, sup);
        this->sort(places, spectrum, inf, index - 1);
        this->sort(places, spectrum, index + 1, sup);
    }
}


int Analyze::place(int places[], const float spectrum[], int inf, int sup){
    int temp(0);
    int inda = inf;
    float a = spectrum[places[inf]];
    inf++;
    while(sup >= inf){

        if(spectrum[places[inf]] > a){
            while(sup >= inf && spectrum[places[sup]] > a){
                sup--;
            }
            if(sup >= inf){
                temp = places[sup];
                places[sup] = places[inf];
                places[inf] = temp;
                sup--;
            }
        }
        inf++;
    }
    temp = places[sup];
    places[sup] = places[inda];
    places[inda] = temp;
    return sup;
}



Note* Analyze::getNote(float frequency, float *diff){
    Note *n = 0;
    Notes *Inotes = Notes::get_instance();
    Note **notes = Inotes->getNotes();
    if(frequency < (notes[0]->getFrequency() + notes[1]->getFrequency()) / 2){
        return notes[0];
    }else if(frequency > (notes[118]->getFrequency() + notes[119]->getFrequency()) / 2 ){
        return notes[119];
    }
    int min(0), max(119), index(0);
    //Number of notes
    bool found = false, stop = false;
    float freqNote(0), diffMin(0), diffMax(0);
    while(!found && min <= max && !stop){
        index = (max + min) / 2;
        //Frequency of the note that being test
        freqNote = notes[index]->getFrequency();
        //If we have found the frequency
        if(frequency == freqNote){
            found = true;
            n = notes[index];
            *diff = 0;
        }else{
            if(frequency < freqNote){
                max = index - 1;
            }else{
                min = index + 1;
            }
        }
    }
    int sign(0);
    if(!found){
        diffMin = frequency - notes[min]->getFrequency();
        if(diffMin < 0){
            diffMin = -diffMin;
            sign = -1;
        }
        diffMax = frequency - notes[max]->getFrequency();
        if(diffMax < 0 ){
            diffMax = -diffMax;
            sign = -1;
        }
        if(diffMax <= diffMin){
            n = notes[max];
            if(diff != 0){
                *diff = sign * diffMax;
            }
            std::cout << "diffMax" << diffMax << std::endl;
        }else{
            n = notes[min];

            std::cout << "diffin" << diffMax << std::endl;

            if(diff != 0){
                *diff = sign * diffMin;
            }
        }
    }
    return n;
}

Note *Analyze::getNote(float frequency){
    float diff = 0;
    Note *n = this->getNote(frequency, &diff);
    return n;
}
