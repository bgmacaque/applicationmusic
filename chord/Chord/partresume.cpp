#include "partresume.h"

PartResume::PartResume(TabChooser *p, QString name, int id ,int height = 50) : part_name(name), part_id(id)
{
    this->parent = p;
    this->setMinimumSize(((QWidget *)this->parent())->width(), height);

    btnDelete = new QPushButton();
    btnDownload = new QPushButton();
    destinationFolder = new QLineEdit("", this);

    connect(btn_delete, SIGNAL(clicked()), this, SLOT(deletePart()));
    connect(btn_download, SIGNAL(clicked()), this, SLOT(downloadPart()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(destinationFolder);
    layout->addWidget(btnDelete);
    layout->addWidget(btnDownload);

    this->setLayout(layout);
    this->show();
}

PartResume::deletePart()
{

}

PartResume::downloadPart()
{
    Configuration conf = this->parent->conf();
    DBConnection connection = this->parent->connection();
}
