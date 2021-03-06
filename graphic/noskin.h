#ifndef NOSKIN_H
#define NOSKIN_H

#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QList>
#include <QMenuBar>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>

#include "dbconnection.h"
#include "configuration.h"
#include "graphicnote.h"
#include "graphicscore.h"

/*!
 * \class noSkin noskin.h
 * \author ALBERT Vincent, GERRIER Théo, NAJIMI Adonis, STERN Valentin
 * \version 1.0
 * \date 07 december 2012
 * \brief This class is used to represent all windows, no matter its layout.
 *
 */
class NoSkin:QMainWindow
{
friend class Controller;
friend class ConfWindow;
private:

/*!
 * \brief Represents the configurations of the user
 */
    Configuration* config;

    /*!
     * \brief An object to represent the connection with the database
     */
    DBConnection *connection;

    /*!
     * \brief Save the current partition (JSON text)
     */
    QAction *btn_save;

    /*!
     * \brief Import a partition (JSON text)
     */
    QAction *btn_import;

    /*!
     * \brief Export the current partition to the website (JSON text)
     */
    QAction *btn_export;

    /*!
     * \brief Attempt to connect the website if it's not, or refresh the connection
     */
    QAction *btn_refresh;

    /*!
     * \brief Display the list of all partitions on the website
     */
    QAction *btn_cloud_list;

    /*!
     * \brief Change the state of the playing : play/pause
     */
    QAction *btn_play_pause;

    /*!
     * \brief Set the cursor of the playing at the beginning
     */
    QAction *btn_stop;

    /*!
     * \brief Change the state of the recording : play/pause
     */
    QAction *btn_record_pause;

    /*!
     * \brief Show the chord' window to accord the guitar
     */
    QAction *btn_chord;

    /*!
     * \brief Show the options' window
     */
    QAction *btn_options;

    /*!
     * \brief btn_delete
     */
    QAction *btn_delete;

    /*!
     * \brief btn_new
     */
    QAction *btn_new;


    /*!
     * \brief btn_forward
     */
    QAction *btn_forward, *btn_back;

    QLineEdit *choice_name;

    QComboBox *choice_difficulty;

    QSpinBox *choice_tempo;

    /*!
     * \brief Bar that contains top buttons
     */
    QToolBar *topBar;

    /*!
     * \brief Bar that contains bottom buttons
     */
    QToolBar *bottomBar;

    /*!
     * \brief The partitiion currently showed
     */
    //Partition *score;

    GraphicScore *g_score;

    /*!
     * \brief Analyze the input sound to determinate notes
     */
     //Analyze *analyzer;

     /*!
      * \brief A method to load all the icons of the top
      */
     void loadTopIcons();

     /*!
      * \brief Load the icons for the bottom toolbar
      */
     void loadBottomIcons();

     /*!
      * \brief Create the top toolbar
      * \return The top toolbar
      */
     QToolBar *createTopBar();

     /*!
      * \brief Create the bottom toolbar
      * \return The bottom toolbar
      */
     QToolBar *createBottomBar();

public:
    /*!
     * \brief Creates a window with the partition p
     * \param p
     */
    NoSkin(/*Partition *p,*/ int minHeight, int minWidth);

    /*!
     * \brief Creates a window without partitions.
     */
    //NoSkin(int minHeight, int minWidth);

    /*!
     * \brief Show the chord's window
     */
    void openChord();

    /*!
     * \brief Show the options' window
     */
    void openOptions();

    /*!
     * \brief Add a partition to the list
     * \param p The partition to add
     */
    //void addPartition(Partition p);

    /*!
     * \brief Exports the current partition to the website when the user is connected.
     * \exception NotConnected If the user is not connected
     */
    bool exportToWeb();

    /*!
     * \brief Import a file from the computer
     * \param path Path of the file to import. This file must be a JSON file.
     * \return The partition we just imported
     * \exception NotJSON If the file is not a JSON text
     */
    //Partition import(QString path);

    /*!
     * \brief Change the position of the playing's cursor
     * \param pos The new position of the cursor
     */
    int changePlayBackPosition(int pos);

    /*!
     * \brief Change the record's cursor position
     * \param position The new position of the cursor
     */
    int changeRecordPosition(int position);

    /*!
     * \brief Record input sounds.
     */
    void record();

    /*!
     * \brief The location of the icons
     */
    QString* icons_loc;

    Configuration* getConf();

    void reloadConf();

};

#endif // NOSKIN_H
