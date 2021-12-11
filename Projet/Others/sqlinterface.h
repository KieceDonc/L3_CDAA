#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "../Model/contact.h"
#include "../Model/structID.h"

/**
 * @brief The SQLInterface class allows interactions between the user and the database using QObjects
 */
class SQLInterface : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase database;
    bool DBOpen;

    void connectDB(const QString &);
    void closeDB();
    bool setDBOpen();

public:
    explicit SQLInterface(QObject *parent = nullptr);
    ~SQLInterface();

    Contact* getContactFromQuery(const QSqlQuery& query);

    void getAllContacts(std::list<ContactID>&);
    void insertContact(Contact & c, std::list<ContactID> * = nullptr);

signals:

};

#endif // SQLINTERFACE_H
