#ifndef NOTES_H
#define NOTES_H
#include "note.h"

class Notes{

private:
//    Note **m_notes;
    Notes();
    static Notes *m_instance;

public:
    static Notes *get_instance();

};


#endif // NOTES_H
