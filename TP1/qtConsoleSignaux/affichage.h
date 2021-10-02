//R.Raffin, UBFC
/* Définition de la classe Affichage
 * doit être un Q_OBJECT pour utiliser les signaux/slots
 * déclaration d'un slot (réception d'un signal) qui lancera la fonction "affiche()"
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QObject>
#include <QString>

class Affichage : public QObject
{
	Q_OBJECT

public:
	//constructeur d'Affichage
	explicit Affichage(QObject *parent = nullptr);

signals:

public slots:
	void affiche(QString);
};

#endif // AFFICHAGE_H
