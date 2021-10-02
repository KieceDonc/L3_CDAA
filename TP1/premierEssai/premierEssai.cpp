//RRaffin, UBFC
/*Premier exemple de QT du module  CDAA
accompagné d'un .pro, il permet d'utiliser une sortie qDebug
Pas encore d'application QT, viendra ensuite
processus de compilation :
qmake
make
./premierEssai
*/

#include <QtCore>
#include <QDebug>
#include <QString>
#include <iostream>

int main()
{
	QString chaine("Ça c'est une chaîne en utf8 ‽ yolo да"); //juste pour avoir un caractère particulier, exclarrogatif (cf https://fr.wikipedia.org/wiki/Point_exclarrogatif)) et un peu de Russe

	//une sortie qDebug (attention à la casse) est disponible (correspond à std::cerr en C++ standard)
	qDebug() << "Sortie qDebug -> " << chaine;

	//attention QT utilise ses propres types, il faudra convertir pour retrouver du C++ standard
	std::cout << "Sortie std::cout -> " << chaine.toStdString() << std::endl;

//n'oubliez pas !
return (0);
}
