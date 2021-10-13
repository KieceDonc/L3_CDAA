#include <QApplication>

#include "mainwidget.h"
#include "affichage.h"



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//un widget tout simple (vide)
	mainWidget w;
	w.show();
    Affichage  af;
    af.show();

	return a.exec();
}
