#include "fenetre.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>

fenetre::fenetre(QWidget *parent)
    : QMainWindow(parent)
{
    connexionBDD();
}

fenetre::~fenetre()
{
}

void fenetre::connexionBDD(){
    db = QSqlDatabase::addDatabase("QSQLITE");

    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("/tmp/base.sqlite");

    /*QSqlQuery  query;
    query.prepare("INSERT INTO personne ( nom , prenom , age ) VALUES ( :n, :p, :a )");
    query.bindValue(":n", "Etbianca");
    query.bindValue(":p", "Bernard");
    query.bindValue(":a", 12);
    query.exec();*/

    QSqlQuery _query;
    _query.prepare("DELETE FROM personne WHERE nom=Bernard");
    _query.exec();

    if(!db.open()){
      qDebug() << "Pas de connexion BDD !";
    }else{
      qDebug() << "Connexion BDD ok";
      QSqlQuery query;
      query.prepare("SELECT * from Personne");

      if(!query.exec()){
          qDebug() << "Impossible d'exécuter la requête !";
      }else{
          qDebug() << "Requête exécutée";
          while(query.next()){
              //le value(0) est l'idPersonne
              qDebug() << "nom : " << query.value(1).toString();
              qDebug() << "prenom : " << query.value(2).toString();
              qDebug() << "age : " << query.value(3).toString();
          }
      }
    }
}

