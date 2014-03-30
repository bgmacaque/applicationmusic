#ifndef PARTRESUME_H
#define PARTRESUME_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include "tabchooser.h"

class PartResume : public QWidget
{
    Q_OBJECT

private:

    QString part_name;
    int part_id;
    TabChooser *parent;

    QPushButton *btnDownload;
    QPushButton *btnDelete;
    QLineEdit *destinationFolder;

public:
    PartResume(TabChooser *parent = 0, QString name, int id, int height);

public slots:

    /*!
     * \brief deletePart
     * Delete the partition in the database
     */
    void deletePart();

    /*!
     * \brief download
     * Download the partition
     */
    void downloadPart();

};

#endif // PARTRESUME_H
