#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPushButton>
#include <QString>

class mainWidget : public QWidget
{
	Q_OBJECT

public:

    bool mouseTracking;

    mainWidget(QWidget *parent = 0);
	~mainWidget();

    QPushButton * b_toggleMouseTracking;

	//on surcharge les fonctions d'un widget (cf doc QT)
	void keyPressEvent(QKeyEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);

signals:
    void sendData(QString);

public slots:
    void toggleMouseTracking();
};

#endif // MAINWIDGET_H
