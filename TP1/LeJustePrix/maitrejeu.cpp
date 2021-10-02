#include "maitrejeu.h"
#include <stdlib.h>

MaitreJeu::MaitreJeu(QObject *parent) : QObject(parent)
{
    srand (time(NULL));
    this->secret = rand()%100;
}

void MaitreJeu::evalue(unsigned int value){
    QString toSend;
    bool playerAsWin = 0;

    if(value < this->secret){
        toSend = "Plus grand frr";
    }else if(value > this->secret){
        toSend = "Plus petit frr";
    }else{
        toSend = "Bien joué fréro, du coup on sort de l'appli";
        emit avis(toSend);
        emit victoire();
        playerAsWin = 1;
    }

    if(!playerAsWin){
        emit incrementeNbCoups();
        QString coups;
        emit afficheCoups(coups.setNum(nbcoups));
        emit avis(toSend);
        emit doitContinuer();
    }
}

void MaitreJeu::incrementationCoups(){
    this->nbcoups++;
}

/*void MaitreJeu::drawNumber(){
    srand (time(NULL));
    this->secret = rand()%100;
}*/
