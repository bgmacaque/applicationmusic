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

    QCheckBox* pass_saved;
    QCheckBox* login_at_start;
    QCheckBox* relogin_after_errors;

    QSpinBox* reloging_after;

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


public:
    ConfWindow(NoSkin *parent);

public slots:
    void setAuthPage();
    void setOptionsPage();
    void setSkinsPage();
};

#endif // CONFWINDOW_H
