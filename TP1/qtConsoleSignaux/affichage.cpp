//R.Raffin, UBFC
/* les méthodes de la classe affichage, utilise std::cout, donc il faut inclure "iostream"
 */

#include <iostream>

#include "affichage.h"

Affichage::Affichage(QObject *parent) : QObject(parent)
{
	//rien de particulier à la construction
}

void Affichage::affiche(QString texte)
{
	//comme d'habitude, il faut récupérer un type C++ compatible
	std::cout << "Affichage: affiche() -> " << texte.toStdString() << std::endl;
}
