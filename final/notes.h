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
    /*!
     * \brief Get the unique instance of the application
     */
    static Notes *get_instance();
    static void kill();

    /*!
     * \brief Get all the notes
     */
    Note **getNotes() const;

    /*!
     * \brief Get the frets of a note
     */
    Note **getNotesFrets(std::string noteName, int nbFrets) const;

    /*!
     * \brief Get a note with its name
     */
    Note *searchNote(std::string name) const;

    /*!
     * \brief Get the index of a note
     */
    int getIndex(std::string name) const;
};


#endif // NOTES_H
