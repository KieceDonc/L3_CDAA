#include "sqlinterface.h"
#include "contactID.h"

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
    connectDB(DBPath);
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

/**
 * @brief Fills an empty contact list with all the contacts from the DB. EMPTIES THE LIST!
 * @param lst a list of contacts
 */
void SQLInterface::getAllContacts(std::list<ContactID> & lst){

    lst.clear();

    if(DBOpen){
        QString queryString = "SELECT * FROM contact";
        QSqlQuery query(queryString);
        if(!query.exec()){
            qDebug() << "Requête impossible : " << queryString;
        }
        else{
            qDebug() << "Requête réussie : " << queryString;



        }
    }

}






