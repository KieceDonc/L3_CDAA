#include "penduleechec.h"
#include "horlogeseule.h"
#include "QHBoxLayout"
#include "QMessageBox"

PenduleEchec::PenduleEchec(QWidget *parent) : QWidget (parent){
    QHBoxLayout* penduleLayout = new  QHBoxLayout ();

    this->horloge0 = new horlogeSeule(this);
    this->horloge1 = new horlogeSeule(this);

    penduleLayout->addWidget(horloge0);
    penduleLayout->addWidget(horloge1);

    setLayout(penduleLayout);
    connect(horloge0, SIGNAL(onEndCountSignal()), horloge1, SLOT(stopCountdown()));
    connect(horloge1, SIGNAL(onEndCountSignal()), horloge0, SLOT(stopCountdown()));
    connect(horloge0, SIGNAL(onEndCountSignal()), this, SLOT(onEndCount()));
    connect(horloge1, SIGNAL(onEndCountSignal()), this, SLOT(onEndCount()));

}

PenduleEchec::~PenduleEchec(){
    free(horloge0);
    free(horloge1);
}


void PenduleEchec::onEndCount(){
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setText("Le décompte est arrivé à sa fin");
    msgBox->exec();
}
