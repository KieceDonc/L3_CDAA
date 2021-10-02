//R.Raffin, UBFC
/* Définition de la classe Traitement
 * cela doit être un Q_OBJECT pour utiliser les signaux/slots
 * déclaration d'un signal "finTraitement" émis en fin de "calcul()"
 */

#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <QObject>

class Traitement: public QObject
{
	Q_OBJECT

public:
	//constructeur
	explicit Traitement(QObject *parent = nullptr);

	//fonction de calcul
	void calcul(unsigned);

signals:
	void finTraitement(QString);
};

#endif // TRAITEMENT_H
