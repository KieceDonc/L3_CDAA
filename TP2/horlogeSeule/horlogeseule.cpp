#include "horlogeseule.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QString>
#include <QMessageBox>

horlogeSeule::horlogeSeule(QWidget *parent): QWidget(parent){
    this->canCount = false;
    compteur = 3;
    texte = new  QLabel("Compteur :", this);
    valeur = new  QLabel(this);
    valeur->setNum ((int)compteur);
    start = new  QPushButton("Démarrer", this);
    stop = new  QPushButton("Arrêter", this);
    this->timer = new QTimer(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* textLayout = new QHBoxLayout(this);
    textLayout -> addWidget(texte);
    textLayout -> addWidget(valeur);

    QHBoxLayout* buttonsLayout = new QHBoxLayout(this);
    buttonsLayout -> addWidget(start);
    buttonsLayout -> addWidget(stop);

    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(buttonsLayout);

    connect(start, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));
    connect(stop, SIGNAL(clicked()), this, SLOT(stopCountdown()));
}

horlogeSeule::~horlogeSeule(){
    free(texte);
    free(valeur);
    free(start);
    free(stop);
    free(timer);
}

void horlogeSeule::timerSlot(){
    if(canCount){
        this->compteur-=1;
        if(this->compteur <= 0){
            this->canCount = false;
            this->valeur->setNum(0);
            disconnect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
            emit onEndCountSignal();
        }else{
            this->valeur->setNum((int)this->compteur);
        }
    }
}

void horlogeSeule::onStartButtonClicked(){
    if(!canCount && this->compteur >0){ // we check if we're already counting
        canCount = true;
        connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
        timer->start(1000);
    }
}

void horlogeSeule::stopCountdown(){
    this->canCount = false;
    disconnect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
}

