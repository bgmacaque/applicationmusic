#include "analyze.h"

#define SPECTRUM_SIZE 8192

//Juste during debug
using namespace std;

static const char *note[120] =
{
    "C0", "C#0", "D0", "D#0", "E0", "F0", "F#0", "G0", "G#0", "A0", "A#0", "B0",
    "C1", "C#1", "D1", "D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
    "C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
    "C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
    "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
    "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5",
    "C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6",
    "C7", "C#7", "D7", "D#7", "E7", "F7", "F#7", "G7", "G#7", "A7", "A#7", "B7",
    "C8", "C#8", "D8", "D#8", "E8", "F8", "F#8", "G8", "G#8", "A8", "A#8", "B8",
    "C9", "C#9", "D9", "D#9", "E9", "F9", "F#9", "G9", "G#9", "A9", "A#9", "B9"
};

static const float notefreq[120] =
{
      16.35f,   17.32f,   18.35f,   19.45f,    20.60f,    21.83f,    23.12f,    24.50f,    25.96f,    27.50f,    29.14f,    30.87f,
      32.70f,   34.65f,   36.71f,   38.89f,    41.20f,    43.65f,    46.25f,    49.00f,    51.91f,    55.00f,    58.27f,    61.74f,
      65.41f,   69.30f,   73.42f,   77.78f,    82.41f,    87.31f,    92.50f,    98.00f,   103.83f,   110.00f,   116.54f,   123.47f,
     130.81f,  138.59f,  146.83f,  155.56f,   164.81f,   174.61f,   185.00f,   196.00f,   207.65f,   220.00f,   233.08f,   246.94f,
     261.63f,  277.18f,  293.66f,  311.13f,   329.63f,   349.23f,   369.99f,   392.00f,   415.30f,   440.00f,   466.16f,   493.88f,
     523.25f,  554.37f,  587.33f,  622.25f,   659.26f,   698.46f,   739.99f,   783.99f,   830.61f,   880.00f,   932.33f,   987.77f,
    1046.50f, 1108.73f, 1174.66f, 1244.51f,  1318.51f,  1396.91f,  1479.98f,  1567.98f,  1661.22f,  1760.00f,  1864.66f,  1975.53f,
    2093.00f, 2217.46f, 2349.32f, 2489.02f,  2637.02f,  2793.83f,  2959.96f,  3135.96f,  3322.44f,  3520.00f,  3729.31f,  3951.07f,
    4186.01f, 4434.92f, 4698.64f, 4978.03f,  5274.04f,  5587.65f,  5919.91f,  6271.92f,  6644.87f,  7040.00f,  7458.62f,  7902.13f,
    8372.01f, 8869.84f, 9397.27f, 9956.06f, 10548.08f, 11175.30f, 11839.82f, 12543.85f, 13289.75f, 14080.00f, 14917.24f, 15804.26f
};


Analyze::Analyze(FMOD::System *p_system, FMOD::Sound *p_sound){
    //Init the tab
    m_notes = new Note*[120];
    int i(0);
    for(i = 0; i < 120; i++){
        //Init the notes
        m_notes[i] = new Note(note[i], notefreq[i]);
    }
    m_system = p_system;
    m_sound = p_sound;
}

Analyze::~Analyze(){
    int i(0);
    for(i = 0; i < 120; i++){
        delete m_notes[i];
    }
    delete[] m_notes;
}


void Analyze::start(){
    m_channel = 0;
    int result(0);
    result = m_system->recordStart(0, m_sound, true);
    result = m_system->playSound(FMOD_CHANNEL_REUSE, m_sound, false, &m_channel);
//    result = m_channel->setVolume(0);
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
//        cout << n->getFrequency() << endl;
//        cout << spectrum[places[i]] << endl;
        if(spectrum[places[i]] < 0.025){
            stop = true;
        }else{
            n = this->getNote(this->getFrequency(places[i]));
            if(!c->contains(n) && n->getFrequency() >= freqMin && n->getFrequency() <= freqMax){
                c->addNote(n);
            }
            i--;
        }
        //        cout << spectrum[places[i]] << endl;
    }
    *maxVolume = spectrum[places[0]];
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
    if(frequency < (m_notes[0]->getFrequency() + m_notes[1]->getFrequency()) / 2){
        return m_notes[0];
    }else if(frequency > (m_notes[118]->getFrequency() + m_notes[119]->getFrequency()) / 2 ){
        return m_notes[119];
    }
    int min(0), max(119), index(0);
    //Number of notes
    bool found = false, stop = false;
    float freqNote(0), diffMin(0), diffMax(0);
    while(!found && min <= max && !stop){
        index = (max + min) / 2;
        //Frequency of the note that being test
        freqNote = m_notes[index]->getFrequency();
        //If we have found the frequency
        if(frequency == freqNote){
            found = true;
            n = m_notes[index];
        }else{
            if(frequency < freqNote){
                max = index - 1;
            }else{
                min = index + 1;
            }
        }
    }
    if(!found){
        diffMin = frequency - m_notes[min]->getFrequency();
        if(diffMin < 0){
            diffMin = -diffMin;
        }
        diffMax = frequency - m_notes[max]->getFrequency();
        if(diffMax < 0 ){
            diffMax = -diffMax;
        }
        if(diffMax <= diffMin){
            n = m_notes[max];
            if(diff != 0){
                *diff = diffMax;
//                std::cout << "Différence : " << *diff << ", note : " << m_notes[max]->getFrequency() << " fréquence : " <<  frequency << std::endl;
            }
        }else{
            n = m_notes[min];
            if(diff != 0){
                *diff = diffMin;
//                std::cout << "Différence : " << *diff << ", note : " << m_notes[max]->getFrequency() << " fréquence : " <<  frequency << std::endl;
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


Note *Analyze::searchNote(std::string name){
    Note *n = 0;
    bool found = false;
    int i(0);
    while(i < 120 && !found){
        if(m_notes[i]->getName().compare(name) == 0){
            found = true;
            n = m_notes[i];
        }
        i++;
    }
    return n;
}
