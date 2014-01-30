#ifndef CONFWINDOW_H
#define CONFWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QToolBar>
#include "noskin.h"

/*!
 * \class ConfWindow confwindow.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class allows the user to change his configurations and preferences.
 */

class ConfWindow:QMainWindow
{
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
     * \brief Layout containing tabs and pages
     */
    QHBoxLayout *main_lay;

    //All buttons to navigate (will be in the tab)
    QAction* btn_connection;
    QAction* btn_options;
    QAction* btn_skins;

    //All pages of the window
    QWidget* page_connection;
    QWidget* page_options;
    QWidget* page_skins;

    //The authentification page
    QFormLayout *layout_connection;
    QLineEdit* username;
    QLineEdit* password;
    bool pass_saved;
    bool login_at_start;
    bool relogin_after_errors;
    int reloging_after;

    //The options page


    //The skins page

    /*!
     * \brief Loads tabs to navigate between pages
     */
    void loadTabs();

    /*!
     * \brief Load the auth page
     */
    void loadAuthPage();

    /*!
     * \brief load the otpion page
     */
    void loadOptionsPage();

    /*!
     * \brief Loads the skin page
     */
    void loadSkinsPage();


public:
    ConfWindow(NoSkin *parent);
};

#endif // CONFWINDOW_H
