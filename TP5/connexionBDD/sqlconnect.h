#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include "contact.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QSqlError>

class sqlconnect{
    public:
        sqlconnect();
        void createTable();
        void addContact(Contact contact);
        int getUniqueID(Contact contact);
    private:
        QSqlDatabase db;
        const std::string url = "/mnt/3822CDE622CDA8E8/Coding_workplace/L3_CDAA/TP5/connexionBDD";

        bool execQuery(QSqlQuery query);
};

#endif // SQLCONNECT_H
