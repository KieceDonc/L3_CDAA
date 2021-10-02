//R.Raffin, UBFC
/* les méthodes de la classe Traitement, on inclut "QDebug" puisqu'on utilisera "qDebug()"
 */

#include <QDebug>

#include "traitement.h"

Traitement::Traitement(QObject *parent) : QObject(parent)
{
	//rien de particulier à la construction
}

//la fonction de calcul ne fait pas grand-chose, elle emet un résultat "en dur", un QString qui vaut "10"
void Traitement::calcul(unsigned v)
{
	qDebug() << "Traitement::calcul()" ;

	QString s;
	s.setNum(v+1);
	//émission du signal de fin de traitement
	emit finTraitement(s);
}
