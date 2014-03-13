#ifndef NOTES_H
#define NOTES_H
#include "note.h"

/*!
 * \class Notes notes.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class represents all the notes available
 * \brief The attribut **m_notes is the array of all the notes available
 * \brief The static attribut *m_instance is the single instance of all the notes available
 */\

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
    Note **getNotesFrets(std::string noteName, int nbFrets) const;
    Note *searchNote(std::string name) const;
    int getIndex(std::string name) const;
};


#endif // NOTES_H
