#include "sqlinterface.h"
#include "../Model/structID.h"

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
    QString DBPath = "../Projet/Database/ContactManagementDB.sqlite" ;
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
 * @brief Create a pointer of contact from query. Don't forget to delete it
 * @param query
 * @return Contact*
 */
Contact* SQLInterface::getContactFromQuery(const QSqlQuery& query){
    return new Contact(query.value(1).toString().toStdString(),
                       query.value(2).toString().toStdString(),
                       query.value(3).toString().toStdString(),
                       query.value(4).toString().toStdString(),
                       query.value(5).toString().toStdString(),
                       Photo());
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
            qDebug() << "Requête de lecture impossible : " << queryString;
        }
        else{
            qDebug() << "Requête de lecture réussie : " << queryString;
            while(query.next()){
                lst.push_back(ContactID{query.value(0).toInt(),getContactFromQuery(query)});
            }
        }
    }
}

void SQLInterface::insertContact(Contact & c, std::list<ContactID> * lst){

    if(DBOpen){
        QString queryString = "INSERT INTO contact (firstname,lastname,entreprise,mail,phone,dateofcreation,photo) VALUES (:fn,:ln,:entr,:mail,:phone,:doc,NULL)";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":fn",QString::fromStdString(c.getFirstName()));
        query.bindValue(":ln",QString::fromStdString(c.getLastName()));
        query.bindValue(":entr",QString::fromStdString(c.getEnterprise()));
        query.bindValue(":mail",QString::fromStdString(c.getMail()));
        query.bindValue(":phone",QString::fromStdString(c.getPhone()));
        query.bindValue(":doc",QString::fromStdString(c.getDateOfCreation().toString()));

        if(!query.exec())
            qDebug()<<"Requête d'insertion impossible";
        else{
            qDebug()<<"Requête d'insertion réussie";
            // To add a contact in the ContactID list, we need its ID, which is the most recent record in the contact table
            if(lst != nullptr){
                QSqlQuery query("SELECT contactid FROM contact ORDER BY contactid DESC LIMIT 1;");
                int id = -1;
                while(query.next()){
                    id = query.value(0).toInt();
                }
                lst->push_back(ContactID{id,&c});
            }
        }
    }




}





