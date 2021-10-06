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

    setLayout(mainLayout);
    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(buttonsLayout);

    connect(start,SIGNAL(clicked()),this,SLOT(onStartButtonClicked()));
    connect(stop,SIGNAL(clicked()),this,SLOT(onStopCountdown()));
}

horlogeSeule::~horlogeSeule(){

}

void horlogeSeule::timerSlot(){
    if(canCount){
        this->compteur-=1;
        if(this->compteur <= 0){
            disconnect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
            this->close();
        }else{
            this->valeur->setNum((int)this->compteur);
        }
    }
}

void horlogeSeule::onStartButtonClicked(){
    if(!canCount){ // we check if we're already counting
        canCount = true;
        connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
        timer->start(1000);
    }
}

void horlogeSeule::onStopCountdown(){
    this->canCount = false;
    disconnect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
}

