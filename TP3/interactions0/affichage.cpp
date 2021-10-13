#include "affichage.h"

Affichage::Affichage(QWidget *parent): QWidget(parent){
    Hlayout = new QHBoxLayout(this);
    zoneTexte = new QTextEdit(this);
    LCDnbEvents = new QLCDNumber(this);
    LCDnbEvents->setMinimumWidth(10);
    LCDnbEvents->setMaximumHeight(30);
    LCDnbEvents->setMode(QLCDNumber::Dec);
    Hlayout->addWidget(zoneTexte);
    Hlayout->addWidget(LCDnbEvents);
}

void Affichage::recvData(QString s){
    zoneTexte->append(s);
    this->nbEvents+=1;
    LCDnbEvents->display(nbEvents);
}
