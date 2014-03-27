#include "dbconnection.h"
#include <iostream>

DBConnection::DBConnection(std::string host, std::string dbname, std::string userName, std::string password, int port = 3306)
{
    base = QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName(QString(host.c_str()));
    base.setDatabaseName(dbname.c_str());
    base.setUserName(userName.c_str());
    base.setPassword(password.c_str());
    base.setPort(port);
    base.open();
}

DBConnection::DBConnection(std::string file)
{
    this->id_user = -1;
    std::string host, db, usr, pwd, port;
    std::ifstream stream(file.c_str(), std::ios::in);

    if(stream){

        //We begin by loading all data
        std::getline(stream, host);
        std::getline(stream, db);
        std::getline(stream, usr);
        std::getline(stream, pwd);
        std::getline(stream, port);

        //QMessageBox::information(NULL, "Toto", QString((host+" || "+db+" || "+usr+" || "+pwd+" || "+port).c_str()));

        //The we call the previous constructor
        //DBConnection();
        //base = new QSqlDatabase();
        base = QSqlDatabase::addDatabase("QMYSQL");

        base.setHostName(QString(host.c_str()));
        base.setDatabaseName(QString(db.c_str()));
        base.setUserName(QString(usr.c_str()));
        base.setPassword(QString(pwd.c_str()));
        base.setPort(atoi(port.c_str()));



        if(!base.open()){
            std::cout << "Erreur de connection à la base de données" << std::endl;
        }
        stream.close();

    }else{
        QMessageBox::warning(NULL, "Fichier", "Impossible de charger le fichier de configuration de la base de données");
    }
}

int DBConnection::getPartitions()
{
    QString q("SELECT * FROM Tabs WHERE user_id = :user_id");

    QSqlQuery *query = new QSqlQuery(base);
    query->prepare(q);
    query->bindValue(":user_id", this->id_user);

    query->exec();
//    QString s = query->value(0).toString();

//    Partition *p;
//    return *p;
}

Partition *DBConnection::download(int part_id){
    QString q("SELECT * FROM Tabs WHERE id = :part_id");
    QSqlQuery *query = new QSqlQuery(base);
    query->prepare(q);
    query->bindValue(":part_id", part_id);
    Partition *p;
    query->exec();
    if(query->first()){
        QString path = "./download.tab";
        std::ofstream file(path.toStdString().c_str(), std::ios::out | std::ios::trunc);

        if(file.is_open()){
            //Opening the partition
            file << query->value(2).toString().toStdString();
            file.close();
        }
        p = Partition::load(path.toStdString().c_str());
    }
    return p;
}


bool DBConnection::insert(Partition *p)
{
    QString q("INSERT INTO Tabs(name, file, user_id, note) VALUES (:name, :file, :user_id, :note)");
    QSqlQuery query(base);

    query.prepare(q);
    query.bindValue(":name", QString::fromStdString(p->getName()));
    query.bindValue(":file", p->stringify());
    query.bindValue(":user_id", this->id_user);
    query.bindValue(":note", 0);

    return query.exec();
}

void DBConnection::connectUser(QString login, QString pwd)
{
    if(base.isOpen()){

        QString rq("SELECT id FROM Users WHERE nickname = :login AND password = :password");
        QSqlQuery *query = new QSqlQuery(base);
        query->prepare(rq);

        query->bindValue(":login", login);
        query->bindValue(":password", pwd);

        query->exec();


        if(query->first())
        {
            this->id_user = query->value(0).toInt();
        }else{
            this->id_user = -1;
        }
    }else{
        QMessageBox::critical(NULL, "Erreur", "Impossible de se connecter à la base de données");
    }
}

int DBConnection::getUserId()
{
    return this->id_user;
}
