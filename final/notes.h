#ifndef NOTES_H
#define NOTES_H
#include "note.h"

class Notes{

private:
    Note **m_notes;
    Notes();
    ~Notes();
    static Notes *m_instance;

public:
    static Notes *get_instance();
    static void kill();
    Note **getNotes() const;
    Note *searchNote(std::string name) const;
};


#endif // NOTES_H
