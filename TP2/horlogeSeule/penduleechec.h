#ifndef PENDULEECHEC_H
#define PENDULEECHEC_H

#include "horlogeseule.h"
#include <QWidget>

class PenduleEchec : public QWidget{

    Q_OBJECT

private:
    horlogeSeule* horloge0;
    horlogeSeule* horloge1;
public:
    explicit PenduleEchec(QWidget *parent = nullptr);

public slots:
};

#endif // PENDULEECHEC_H
