#include "penduleechec.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PenduleEchec w;
    w.show();

    return a.exec();
}
