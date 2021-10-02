#include <QObject>
#include <QCoreApplication>
#include <QDebug>

#include "affichage.h"
#include "joueur.h"
#include "maitrejeu.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Lancement de l'application, CTRL-C pour sortir";

    Affichage affichage;
    Joueur joueur;
    MaitreJeu maitreJeu;

    // Qint???????????????????
    QObject::connect(&joueur, SIGNAL(propose(int)),&maitreJeu, SLOT(evalue(int)));
    QObject::connect(&maitreJeu, SIGNAL(evalue(int)), &maitreJeu, SLOT(incrementationCoups()))
    QObject::connect(&maitreJeu, SIGNAL(incrementeNbCoups()), &maitreJeu, SLOT(incrementationCoups()));
    QObject::connect(&maitreJeu, SIGNAL(afficheCoups(QString)), &affichage, SLOT(affiche(QSTRING)));
    QObject::connect(&maitreJeu, SIGNAL(avis(QString)),&affichage, SLOT(affiche(QString)));
    QObject::connect(&maitreJeu, SIGNAL(victoire()),&joueur, SLOT(gagne()));
    QObject::connect(&joueur, SIGNAL(sortie()),&a,SLOT(quit()));




    return a.exec();
}
