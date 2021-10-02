#include "affichage.h"
#include <iostream>

Affichage::Affichage(QObject *parent) : QObject(parent)
{

}

void Affichage::affiche(QString texte)
{
    //comme d'habitude, il faut récupérer un type C++ compatible
    std::cout << "Affichage: affiche() -> " << texte.toStdString() << std::endl;
}
