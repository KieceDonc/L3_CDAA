#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QObject>

class Affichage : public QObject
{
    Q_OBJECT
public:
    explicit Affichage(QObject *parent = nullptr);

signals:

public slots:
    void affiche(QString);
};

#endif // AFFICHAGE_H
