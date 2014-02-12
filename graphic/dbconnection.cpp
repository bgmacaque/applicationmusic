#include "dbconnection.h"

DBConnection::DBConnection(std::string host, std::string dbname, std::string userName, std::string password, int port = 10000)
{
    base = new QSqlDatabase;
    base->setHostName(QString(host.c_str()));
    base->setDatabaseName(dbname.c_str());
    base->setUserName(userName.c_str());
    base->setPassword(password.c_str());
    base->setPort(port);

    base->open();
}

DBConnection::DBConnection(std::string file)
{
    std::string host, db, usr, pwd, port;
    std::ifstream stream(file.c_str(), std::ios::in);

    if(stream){

        //We begin by loading all data
        std::getline(stream, host);
        std::getline(stream, db);
        std::getline(stream, usr);
        std::getline(stream, pwd);
        std::getline(stream, port);

        //The we call the previous constructor
        DBConnection(host, db, usr, pwd, atoi(port.c_str()));
        stream.close();

    }
}

/*Partition DBConnection::select(int id)
{
    QString q("SELECT * FROM Partitions WHERE part_id = :id");

    QSqlQuery *query = new QSqlQuery(*base);
    query->prepare(q);
    query->bindValue(":id", id);

    query->exec();
    QString s = query->boundValue(0).toString();

    Partition *p; //= new Partition(0);
    return *p;
}

bool DBConnection::insert(Partition p)
{
    QString q("INSERT INTO Partitions(part_name, part_file) VALUES (:part_name, :part_file)");
    QSqlQuery query(*base);

    query.prepare(q);
    query.bindValue(":part_name", p.getName().c_str());
    query.bindValue(":part_file", p.toJSON().c_str());

    return query.exec();
}
*/
