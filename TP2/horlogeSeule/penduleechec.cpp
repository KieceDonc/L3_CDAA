#include "penduleechec.h"
#include "horlogeseule.h"
#include "QHBoxLayout"

PenduleEchec::PenduleEchec(QWidget *parent) : QWidget (parent){
    QHBoxLayout* penduleLayout = new  QHBoxLayout ();

    this->horloge0 = new horlogeSeule(this);
    this->horloge1 = new horlogeSeule(this);

    penduleLayout->addWidget(horloge0);
    penduleLayout->addWidget(horloge1);

    setLayout(penduleLayout);
}
