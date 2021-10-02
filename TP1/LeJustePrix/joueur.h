#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>

class Joueur : public QObject
{
    Q_OBJECT

private:
    //le jeu est-il en cours?
    bool running;

public:
    explicit Joueur(QObject *parent = nullptr); // explicit -> ajouté par QTCreator à la création d'une classe hértant de QOBject
    void joue();

signals:
    void propose(unsigned int);
    void sortie();

public slots:
    //recoit le message du mdj et demande la sortie du jeu
    void gagne();
    void doitRejouer();
};

#endif // JOUEUR_H
