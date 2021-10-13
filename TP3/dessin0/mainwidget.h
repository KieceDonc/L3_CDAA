#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QPushButton>

class mainWidget : public QWidget
{
	Q_OBJECT

signals:
	void b_MouseTracking_update(bool);
	void newEvent(QString);

private slots:
	void update_BMouseTracking(bool);
	void toggleMouseTracking();

public:
	mainWidget(QWidget *parent = 0);
	~mainWidget();

	void modifyTrackingMode(const bool&);


	//on surcharge les fonctions d'un widget (cf doc QT)
	void keyPressEvent(QKeyEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);

	QPushButton * b_toggleMouseTracking;
	bool mouseTracking;

	QPointF mousePoint;

protected:
	 void paintEvent(QPaintEvent *event) override;

};


#endif // MAINWIDGET_H
