#include "sqlconnect.h"

sqlconnect::sqlconnect(){
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(this->url.c_str());
    if(!db.open()){
        qDebug() << " Pas de connexion  à la base de données";
    }
}

void sqlconnect::createTable(){
    std::string body = "";
    body+="CREATE TABLE IF NOT EXISTS Personne(";
    body+="idPersonne INTEGER UNIQUE,";
    body+="nom TEXT,";
    body+="prenom TEXT,";
    body+="email TEXT,";
    body+="entreprise TEXT,";
    body+="dateOfCreation DATE";
    body+="PRIMARY KEY(idPersonne AUTOINCREMENT))";

    QSqlQuery query(body.c_str());
    this->execQuery(query);
}

void sqlconnect::addContact(Contact contact){
    std::string body = "";
    body+="INSERT INTO Personne(nom prenom age)";
    body+="values('"+contact.getLastName();
    body+="','"+contact.getFirstName();
    body+="','"+contact.getMail();
    body+="','"+contact.getEnterprise();
    body+="','"+contact.getDateOfCreation().toSQLFormat();
    body+="')'";

    QSqlQuery query(body.c_str());
    this->execQuery(query);
}

int sqlconnect::getUniqueID(Contact contact){
    std::string body = "";
    body+="SELECT idPersonne FROM Personne(nom prenom age) WHERE(";
    body+="nom='"+contact.getLastName()+"'";
    body+="AND prenom='"+contact.getFirstName()+"'";
    body+="AND email='"+contact.getMail()+"'";
    body+="AND entreprise='"+contact.getEnterprise()+"'";
    body+="AND dateOfCreation='"+contact.getDateOfCreation().toSQLFormat()+"'";
    body+=")";

    QSqlQuery query(body.c_str());
    if(this->execQuery(query)){
        return query.value(0).toInt();
    }else{
        return -1;
    }
}

void sqlconnect::removeContact(Contact contact){

}

bool sqlconnect::execQuery(QSqlQuery query){
    if(!query.exec()){
        qDebug() << "Impossible d'exécuter la requête";
        qDebug() << "SqLite error:" << query.lastError().text();
        qDebug() << "SqLite error code:" << query.lastError().number();
        return false;
    }else{
        qDebug() << "Reqûete réussie !";
        return true;
    }
}
