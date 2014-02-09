#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <stdlib.h>
#include <QString>
#include <iostream>
#include <fstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "partition.h"

class DBConnection
{
private:
    QSqlDatabase* base;

public:
    /*!
     * \brief Creates a connection with all parameters
     * \param host Name of the host
     * \param dbname Name of the database
     * \param userName Name of the user
     * \param password Password of the database
     * \param port Port used to communicate with DB (default : 35000)
     */
    DBConnection(std::string host, std::string dbname, std::string userName, std::string password, int port);

    /*!
     * \brief Creates a connection with data of the file
     * \param file Path of a file containing in this order :the host, the dbname, the userName, the password and the port
     */
    DBConnection(std::string file);

    /*!
     * \brief Insert a partition in the database and connect it to the authetified user. If it already exists, then it is updated
     * \param p The partition to add
     * \return True if it succeeded, false in other cases
     */
    bool insert(Partition p);

    /*!
     * \brief Update a partition the athentified user already created
     * \param p Tjhe new version of the partition
     * \return True if it succeeded, false in other case.
     */
    bool update(Partition p);

    /*!
     * \brief Select a particular partition of the authentified user with its id
     * \param id The id of the partition
     * \return The selected partition
     */
    Partition select(int id);

    /*!
     * \brief Select all partitions of the authentified user.
     * \return A vector containing all partitions.
     */
    std::vector<Partition> selectAll();
};

#endif // DBCONNECTION_H
