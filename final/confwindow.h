#ifndef CONFWINDOW_H
#define CONFWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QToolBar>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>

#include "noskin.h"
#include "configuration.h"

/*!
 * \class ConfWindow confwindow.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class allows the user to change his configurations and preferences.
 */

class ConfWindow:QMainWindow
{

    Q_OBJECT

private:
    /*!
     * \brief The parent of the window (in order to apply modifications)
     */
    NoSkin* parent;

    /*!
     * \brief Contains all pages of the window
     */
    QStackedWidget* pages;

    /*!
     * \brief Tabs to change of page
     */
    QToolBar *tabs;

    /*!
     * \brief Button to connect
     */
    QAction* btn_connection;

    /*!
     * \brief Button to access the option
     */
    QAction* btn_options;

    /*!
     * \brief Button for the skins
     */
    QAction* btn_skins;

    /*!
     * \brief Button to apply change
     */
    QPushButton* btn_apply;

    /*!
     * \brief Screen of the connection
     */
    QWidget* page_connection;

    /*!
     * \brief Screen of the options
     */
    QWidget* page_options;

    /*!
     * \brief Screen for the skins
     */
    QWidget* page_skins;

    /*!
     * \brief Layout for the connection
     */
    QFormLayout *layout_connection;

    /*!
     * \brief Input field for the username
     */
    QLineEdit* username;

    /*!
     * \brief Input field for the password
     */
    QLineEdit* password;

    /*!
     * \brief Box to inform the application if the user want his password to be saved
     */
    QCheckBox* pass_saved;

    /*!
     * \brief Box to inform the application if the user want to launch at start
     */
    QCheckBox* login_at_start;

    /*!
     * \brief Box to inform the application if the user wants to relog after an error
     */
    QCheckBox* relogin_after_errors;

    /*!
     * \brief SpinBox for the time between two relogging try
     */
    QSpinBox* reloging_after;

    /*!
     * \brief Loads tabs to navigate between pages
     */
    void loadTabs();

    /*!
     * \brief Load the auth page
     */
    void loadAuthPage();

    /*!
     * \brief load the option page
     */
    void loadOptionsPage();

    /*!
     * \brief Loads the skin page
     */
    void loadSkinsPage();

    /*!
     * \brief To connect signals and slots
     */
    void link();

    /*!
     * \brief Set the configurations of the object configuration in the view
     */
    void setConfig();


public:
    ConfWindow(NoSkin *parent);

public slots:
    /*!
     * \brief Set the authentification page
     */
    void setAuthPage();

    /*!
     * \brief Set the options page
     */
    void setOptionsPage();

    /*!
     * \brief Set the skins page
     */
    void setSkinsPage();

    /*!
     * \brief Apply changements and save them
     */
    void apply();

    /*!
     * \brief To active time of, relogging or  not
     */
    void activeRelogTime(bool activated);

    /*!
     * \brief Active all components if it can be (when the username is not emty).
     *  \return The state of components : true if enabled, false else
     */
    bool activeAll();

    /*!
     * \brief Enable pass_saved if a password is set.
     */
    bool activeSavePass();
};

#endif // CONFWINDOW_H
