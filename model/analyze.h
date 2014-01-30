#ifndef ANALYZE_H
#define ANALYZE_H
#include <fmod.hpp>
#include "note.h"
#include "partition.h"
#include <vector>
class Analyze{
private:
    std::vector<Note> notes;

public:
    Analyze();
    void mainNote(FMOD::Channel *channel);
    Note getNote(int frequency);
    void sort(int places[], float spectrum[], int size, int inf, int sup);
    int place(float spectrum[], int size, int inf, int sup);
    void record(Partition tab);
};

#endif // ANALYZE_H
