#include "sqlinterface.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>

/**
 * @class SQLInterface
 * Data Schema is as follows :
 *
 * Contact
 */

SQLInterface::SQLInterface(QObject *parent) : QObject(parent)
{
    this->DBOpen = false;
    QString DBPath = "../Database/ContactManagementDB.sqlite" ;
    connectDB(DBPath) ;
}

void SQLInterface::connectDB(const QString & uri)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(uri);

    if(database.open()){
        qDebug() << "DB ouverte!";
        DBOpen = true;
    }else{
        qDebug() << "DB non ouverte";
        DBOpen = false;
    }
}

SQLInterface::~SQLInterface(){
    database.close();
    DBOpen = false;
}






