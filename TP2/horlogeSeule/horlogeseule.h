#ifndef HORLOGESEULE_H
#define HORLOGESEULE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class horlogeSeule : public QWidget
{
    Q_OBJECT
private:
    unsigned compteur;
    bool canCount;

public:
    horlogeSeule(QWidget *parent = 0);
    ~horlogeSeule();

    QLabel *texte;
    QLabel *valeur;
    QPushButton *start, *stop;
    QTimer* timer;

signals:
    void exitApp();

public slots:
    void timerSlot();
    void onStartButtonClicked();
    void onStopCountdown();
};

#endif // HORLOGESEULE_H
