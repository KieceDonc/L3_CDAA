#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>

class fenetre : public QMainWindow
{
    Q_OBJECT

private:
    QSqlDatabase db;

public:
    fenetre(QWidget *parent = nullptr);
    ~fenetre();
    void connexionBDD();

};
#endif // FENETRE_H
