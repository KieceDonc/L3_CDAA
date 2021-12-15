#include "sqlinterface.h"
#include "../Model/structid.h"
#include "../Model/date.h"

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
Contact* SQLInterface::getContact(const QSqlQuery& query){

    qDebug() << "Création du contact " << query.value(1).toString();

    //Filling a list with all the contact interactions
    QSqlQuery query2;
    query2.prepare("SELECT interactiondate,interactioncontent FROM contact NATURAL JOIN contactinteraction NATURAL JOIN interaction WHERE contactid = :i;");
    query2.bindValue(":i",query.value(0).toString());
    std::list<Interaction *> lst;
    if(!query2.exec())
        qDebug()<<"Interaction insertion query failed";
    else{
        qDebug()<<"Interaction insertion query successful";
        while(query2.next()){
            lst.push_back(new Interaction(Date(query2.value(0).toString().toStdString()),query2.value(1).toString().toStdString()));
        }
    }

    //Creating the contact with those 2 queries
    Contact * c = new Contact(query.value(1).toString().toStdString(),
                       query.value(2).toString().toStdString(),
                       query.value(3).toString().toStdString(),
                       query.value(4).toString().toStdString(),
                       query.value(5).toString().toStdString(),
                       query.value(7).toString().toStdString(),
                       Date(query.value(6).toString().toStdString()));
    c->setInteractions(lst);

    return c;
}

/**
 * @brief Fills an empty contact list with all the contacts from the DB, and adds the Interactions and Todos to MapInteractionTodo. EMPTIES THE LIST!
 * @param lst a list of contacts
 */
void SQLInterface::getAllContacts(std::list<ContactID> & lstContacts, MapInteractionTodo & mp){
    lstContacts.clear();


    if(DBOpen){
        QString queryString = "SELECT * FROM contact";
        QSqlQuery query(queryString);
        if(!query.exec()){
            qDebug() << "Requête de lecture impossible : " << queryString;
        }
        else{
            qDebug() << "Requête de lecture réussie : " << queryString;
            while(query.next()){

                // Making a list for the contact interactions and for the todos
                QSqlQuery query2;
                query2.prepare("SELECT interactiondate,interactioncontent,interactionid FROM contact NATURAL JOIN contactinteraction NATURAL JOIN interaction WHERE contactid = :c;");
                query2.bindValue(":c",query.value(0).toString());
                std::list<Interaction *> lst;
                if(!query2.exec())
                    qDebug()<<"Interaction insertion query failed";
                else{
                    qDebug()<<"Interaction insertion query successful";
                    while(query2.next()){
                        // Add the interaction to the Contact interaction
                        lst.push_back(new Interaction(Date(query2.value(0).toString().toStdString()),query2.value(1).toString().toStdString()));

                        // And then add the correponding Todos
                        QSqlQuery queryTodos;
                        queryTodos.prepare("SELECT tododate,todocontent FROM interaction NATURAL JOIN interactiontodo NATURAL JOIN todo WHERE interactionid = :i");
                        queryTodos.bindValue(":i",query2.value(2));
                        if(!queryTodos.exec())
                            qDebug() << "Todo insertion query failed";
                        else{
                            qDebug() << "Todo insertion query successful";
                            while(queryTodos.next()){
                                mp.insert(lst.back(),new Todo(Date(queryTodos.value(0).toString().toStdString()),queryTodos.value(1).toString().toStdString()));
                            }
                        }
                    }
                }
                //Creating the contact with those 2 queries
                Contact * c = new Contact(query.value(1).toString().toStdString(),
                                   query.value(2).toString().toStdString(),
                                   query.value(3).toString().toStdString(),
                                   query.value(4).toString().toStdString(),
                                   query.value(5).toString().toStdString(),
                                   query.value(7).toString().toStdString(),
                                   Date(query.value(6).toString().toStdString()));
                c->setInteractions(lst);


                lstContacts.push_back(ContactID{query.value(0).toInt(),c});
            }
        }
    }
}


void SQLInterface::insertContact(Contact & c, std::list<ContactID> * lst){

    if(DBOpen){
        QString queryString = "INSERT INTO contact (firstname,lastname,entreprise,mail,phone,dateofcreation,photo) VALUES (:fn,:ln,:entr,:mail,:phone,:doc,:photo)";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":fn",QString::fromStdString(c.getFirstName()));
        query.bindValue(":ln",QString::fromStdString(c.getLastName()));
        query.bindValue(":entr",QString::fromStdString(c.getEnterprise()));
        query.bindValue(":mail",QString::fromStdString(c.getMail()));
        query.bindValue(":phone",QString::fromStdString(c.getPhone()));
        query.bindValue(":doc",QString::fromStdString(c.getDateOfCreation().toString()));
        query.bindValue(":photo",QString::fromStdString(c.getPhoto()));

        if(!query.exec())
            qDebug()<<"Requête d'insertion de contact impossible";
        else{
            qDebug()<<"Requête d'insertion de contact réussie";
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

void SQLInterface::updateContact(ContactID &c)
{
    QSqlQuery queryUpdate;
    QString queryStringUpdate = "UPDATE contact SET firstname = :fn, lastname = :ln, entreprise = :ent, mail = :mail, phone = :phone, dateofcreation = :date WHERE ContactID = :cid";
    //QString queryStringUpdate = "UPDATE contact SET firstname = \"aaa\", lastname = \"aaa\", entreprise = \"aaa\", mail = \"aaa\", phone = \"aaa\", dateofcreation = \"25-05-2000\" WHERE ContactID = 19";
    queryUpdate.prepare(queryStringUpdate);
    queryUpdate.bindValue(":fn",QString::fromStdString(c.contact->getFirstName()));
    queryUpdate.bindValue(":ln",QString::fromStdString(c.contact->getLastName()));
    queryUpdate.bindValue(":ent",QString::fromStdString(c.contact->getEnterprise()));
    queryUpdate.bindValue(":mail",QString::fromStdString(c.contact->getMail()));
    queryUpdate.bindValue(":phone",QString::fromStdString(c.contact->getPhone()));
    queryUpdate.bindValue(":date",QString::fromStdString(c.contact->getDateOfCreation().toString()));
    queryUpdate.bindValue(":cid",c.id);

    if(!queryUpdate.exec())
        qDebug()<<"Contact update query faiiled";
    else
        qDebug()<<"Contact update query successful";
}

void SQLInterface::deleteContact(ContactID & c)
{
    deleteAllInteractions(c);

    QSqlQuery queryDelete;
    QString queryStringDelete = "DELETE FROM contact WHERE contactid = :cid";
    queryDelete.prepare(queryStringDelete);
    queryDelete.bindValue(":cid",c.id);
    std::list<ContactID>::iterator itContact;

    if(!queryDelete.exec())
        qDebug()<<"Contact deletion query faiiled";
    else
        qDebug()<<"Contact deletion query successful";

}

void SQLInterface::deleteAllInteractions(ContactID &c)
{

    QSqlQuery queryDeleteContactInteractions;
    QSqlQuery queryDeleteInteractionTodos;
    QSqlQuery queryDeleteInteractions;
    QSqlQuery queryDeleteTodos;

    QString queryStringDeleteContactInteractions = "DELETE FROM contactinteraction WHERE contactid = :cid";
    QString queryStringDeleteInteractionTodos = "DELETE FROM interactiontodo WHERE interactionid NOT IN (SELECT interactionid FROM contactinteraction)";
    QString queryStringDeleteInteractions = "DELETE FROM interaction WHERE interactionid NOT IN (SELECT interactionid FROM contactinteraction)";
    QString queryStringDeleteTodos = "DELETE FROM todo WHERE todoid NOT IN (SELECT todoid FROM interactiontodo);";

    queryDeleteContactInteractions.prepare(queryStringDeleteContactInteractions);
    queryDeleteContactInteractions.bindValue(":cid",c.id);

    queryDeleteInteractionTodos.prepare(queryStringDeleteInteractionTodos);
    queryDeleteInteractions.prepare(queryStringDeleteInteractions);
    queryDeleteTodos.prepare(queryStringDeleteTodos);

    if(!queryDeleteContactInteractions.exec())
        qDebug()<<"contactinteraction deletion query faiiled";
    else
        qDebug()<<"contactinteraction deletion query successful";

    if(!queryDeleteInteractionTodos.exec())
        qDebug()<<"interactiontodo deletion query faiiled";
    else
        qDebug()<<"interactiontodo deletion query successful";

    if(!queryDeleteInteractions.exec())
        qDebug()<<"interaction deletion query faiiled";
    else
        qDebug()<<"interaction deletion query successful";

    if(!queryDeleteTodos.exec())
        qDebug()<<"todo deletion query faiiled";
    else
        qDebug()<<"todo deletion query successful";
}

void SQLInterface::addAllInteractions(ContactID &c, MapInteractionTodo &mp)
{

    std::list<Interaction *> lstInter = c.contact->getInteractions();
    std::list<Todo *> lstTodo;
    std::list<Interaction *>::iterator itInter;
    std::list<Interaction *>::iterator itTodo;

    deleteAllInteractions(c);

    for(itInter = lstInter.begin() ; itInter != lstInter.end() ; itInter++){
        lstTodo = mp.at(*itInter);
        qDebug() << "TAILLE LST TODO"<<lstTodo.size();
        this->insertInteraction(c,(*itInter),lstTodo);
    }
}

void SQLInterface::insertInteraction(ContactID &c , Interaction *i, std::list<Todo *> & lstTodo)
{
    QSqlQuery queryInsertInteraction;
    QSqlQuery queryInsertContactInteraction;
    QSqlQuery queryInsertTodo;
    QSqlQuery queryInsertInteractionTodo;
    QSqlQuery queryLastInteractionID;
    QSqlQuery queryLastTotoID;

    QString queryStringInsertInteraction = "INSERT INTO interaction(interactiondate,interactioncontent) VALUES (:idate,:icont);";
    QString queryStringInsertContactInteraction = "INSERT INTO contactinteraction(contactid,interactionid) SELECT :cid,lastinsert.lastid FROM lastinsert WHERE name = \"interactionid\";";
    QString queryStringInsertTodo = "INSERT INTO todo(tododate,todocontent) VALUES (:tdate,:tcont);";
    QString queryStringInteractionTodo = "INSERT INTO InteractionTodo VALUES(:iid,:tid);";
    QString queryStringLastInteractionID = "SELECT lastid FROM lastinsert WHERE name=\"interactionid\";";
    QString queryStringLastTotoID = "SELECT lastid FROM lastinsert WHERE name=\"todoid\";";


    queryInsertInteraction.prepare(queryStringInsertInteraction);
    queryInsertInteraction.bindValue(":idate",QString::fromStdString(i->getDate().toString()));
    queryInsertInteraction.bindValue(":icont",QString::fromStdString(i->getContent()));

    queryInsertContactInteraction.prepare(queryStringInsertContactInteraction);
    queryInsertContactInteraction.bindValue(":cid",QString::number(c.id));

    std::list<Todo *>::iterator itTodo;
    QString interactionID;
    QString todoID;

    if(!queryInsertInteraction.exec())
        qDebug()<<"insert interaction : interaction insertion query failed";
    else{
        qDebug()<<"insert interaction : interaction insertion query successful";
        if(!queryInsertContactInteraction.exec())
            qDebug()<<"insert interaction : contactinteractioninteraction insertion query failed";
        else{
            qDebug()<<"insert interaction : contactinteraction insertion query successful";
            for(itTodo = lstTodo.begin() ; itTodo != lstTodo.end() ; itTodo++){
                qDebug() << "ouaiiiiiiiis";
                queryInsertTodo.prepare(queryStringInsertTodo);
                queryInsertTodo.bindValue(":tdate",QString::fromStdString((*itTodo)->getDate().toString()));
                queryInsertTodo.bindValue(":tcont",QString::fromStdString((*itTodo)->getContent()));


                if(!queryInsertTodo.exec())
                    qDebug()<<"insert interaction : todo insertion query failed";
                else{
                    qDebug()<<"insert interaction : todo insertion query successful";
                    queryLastInteractionID.prepare(queryStringLastInteractionID);
                    queryLastInteractionID.exec();
                    queryLastInteractionID.next();
                    interactionID = queryLastInteractionID.value(0).toString();

                    queryLastTotoID.prepare(queryStringLastTotoID);
                    queryLastTotoID.exec();
                    queryLastTotoID.next();
                    todoID = queryLastTotoID.value(0).toString();

                    queryInsertInteractionTodo.prepare(queryStringInteractionTodo);
                    queryInsertInteractionTodo.bindValue(":iid",interactionID);
                    queryInsertInteractionTodo.bindValue(":tid",todoID);
                    qDebug() << queryStringInteractionTodo << " | InteractionID:" << interactionID << " | todoID:" << todoID;
                    if(!queryInsertInteractionTodo.exec())
                        qDebug()<<"insert interaction : interactiontodo insertion query failed";
                    else{
                        qDebug()<<"insert interaction : interactiontodo insertion query successful";
                    }
                }
            }
        }
    }
}





