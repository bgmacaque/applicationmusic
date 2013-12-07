#ifndef NOSKIN_H
#define NOSKIN_H

#include <QMainWindow>
#include <QAction>
#include <QList>
#include "../model/partition.h"

/*!
 * \class noSkin noskin.h
 * \author ALBERT Vincent, GERRIER Théo, NAJIMI Adonis, STERN Valentin
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is used to represent all windows, no matter its layout.
 *
 */
class noSkin:QMainWindow
{
private:
    /*!
     * \brief Save the current partition (JSON text)
     */
    QAction btn_save;

    /*!
     * \brief Import a partition (JSON text)
     */
    QAction btn_import;

    /*!
     * \brief Export the current partition to the website (JSON text)
     */
    QAction btn_export;

    /*!
     * \brief Attempt to connect the website if it's not, or refresh the connection
     */
    QAction btn_refresh;

    /*!
     * \brief Display the list of all partitions on the website
     */
    QAction btn_cloud_list;

    /*!
     * \brief Change the state of the playing : play/pause
     */
    QAction btn_play_pause;

    /*!
     * \brief Set the cursor of the playing at the beginning
     */
    QAction btn_stop;

    /*!
     * \brief Change the state of the recording : play/pause
     */
    QAction btn_record_pause;

    /*!
     * \brief Show the chord' window to accord the guitar
     */
    QAction btn_chord;

    /*!
     * \brief Show the options' window
     */
    QAction btn_options;

    /*!
     * \brief List of partitions
     */
    QList partition_list; //or just one partition ????

    /*!
     * \brief Analyze the input sound to determinate notes
     */
    // QAnalyzer analyzer;


public:
    /*!
     * \brief Creates a window with the partition p
     * \param p
     */
    noSkin(Partition p);

    /*!
     * \brief Creates a window without partitions.
     */
    noSkin();

    /*!
     * \brief Show the chord's window
     */
    openChord();

    /*!
     * \brief Show the options' window
     */
    openOptions();

    /*!
     * \brief Add a partition to the list
     * \param p The partition to add
     */
    addPartition(Partition p);

    /*!
     * \brief Exports the current partition to the website when the user is connected.
     * \exception NotConnected If the user is not connected
     */
    exportToWeb();

    /*!
     * \brief Import a file from the computer
     * \param path Path of the file to import. This file must be a JSON file.
     * \return The partition we just imported
     * \exception NotJSON If the file is not a JSON text
     */
    Partition import(QString path);

    /*!
     * \brief Change the position of the playing's cursor
     * \param pos The new position of the cursor
     */
    changePlayBackPosition(int pos);

    /*!
     * \brief Try to connect the user to the website
     * \exception NotConnected If it doesn't work
     */
    connectToWeb();

    /*!
     * \brief Change the record's cursor position
     * \param position The new position of the cursor
     */
    changeRecordPosition(int position);

    /*!
     * \brief Record input sounds.
     */
    record();

};

#endif // NOSKIN_H
