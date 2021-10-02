#ifndef MAITREJEU_H
#define MAITREJEU_H

#include <QObject>

class MaitreJeu : public QObject
{
    Q_OBJECT

private:
    unsigned secret ;
    unsigned nbcoups ;

public:
    explicit MaitreJeu(QObject *parent = nullptr);
    //void drawNumber();

signals:
    void avis(QString);
    void incrementeNbCoups();
    void afficheCoups(QString);
    void victoire();

public slots:
    // reçoit et évalue la proposition du joueur
    void evalue ( unsigned ) ;

    // ce slot peut être " private " car de MdJ à lui - même
    void incrementationCoups() ;

};

#endif // MAITREJEU_H
