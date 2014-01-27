#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include <vector>
class Analyze{
private:
    std::vector<Note> notes;

public:
    Analyze();
    void showNote(FMOD::Channel *channel);
    Note getNote(int frequency);
    void sort(float spectrum[], int size, int inf, int sup);
    int place(float spectrum[], int size, int inf, int sup);
};

#endif // ANALYZE_H
