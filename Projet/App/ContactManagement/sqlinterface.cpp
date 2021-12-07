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
            while(query.next()){
                Contact * c = new Contact(query.value(1).toString().toStdString(),
                                          query.value(2).toString().toStdString(),
                                          query.value(3).toString().toStdString(),
                                          query.value(4).toString().toStdString(),
                                          query.value(5).toString().toStdString(),
                                          Photo());
                lst.push_back(ContactID{query.value(0).toInt(),c});
            }
        }
    }

}






