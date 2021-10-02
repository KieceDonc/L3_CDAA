//R.Raffin, UBFC
/* Application comprenant une console Qt et des échange de signaux entre fonctions
 * Utilisation :
 * qmake
 * make
 */

#include <QObject>
#include <QCoreApplication>
#include <QDebug>

//les classes pour le traitement et l'affichage
#include "traitement.h"
#include "affichage.h"

int main(int argc, char *argv[])
{
	//déclaration d'une application QT
	QCoreApplication app(argc, argv);

	qDebug() << "Lancement de l'application, CTRL-C pour sortir";

	//une instance de chaque classe
	Traitement trait;
	Affichage aff;

	//la connexion du signal "finTraitement()" du traitement avec "affiche()" de Affichage - attention aux types identiques des arguments
	QObject::connect(&trait, SIGNAL(finTraitement(QString)), &aff, SLOT(affiche(QString)));

	//lancement du calcul dans le traitement
	trait.calcul(15);

	//l'application QT tourne en boucle
	return app.exec();
}
