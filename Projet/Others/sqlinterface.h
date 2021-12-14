#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <Model/mapinteractiontodo.h>
#include <Model/todo.h>

#include "../Model/contact.h"
#include "../Model/structid.h"

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

    Contact* getContact(const QSqlQuery& query);
    void getAllContacts(std::list<ContactID>&, MapInteractionTodo&);
    void insertContact(Contact & c, std::list<ContactID> * = nullptr);
    void deleteAllInteractions(ContactID & c);
    void addAllInteractions(ContactID &c, MapInteractionTodo & mp);
    void insertInteraction(ContactID &c , Interaction * , std::list<Todo *> &);

signals:

};

#endif // SQLINTERFACE_H
