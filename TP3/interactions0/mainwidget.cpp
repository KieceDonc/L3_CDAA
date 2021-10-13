#include <QDebug>
#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent): QWidget(parent){
    //on donne une taille par défaut à notre widget (en pixels) (largeur, hauteur)
    setFixedSize(300,300);
    b_toggleMouseTracking = new QPushButton("",this);
    b_toggleMouseTracking->setFixedSize(300,100);
    //b_toggleMouseTracking->setDisabled(true);

    //pour pouvoir suivre "en temps-réel" le déplacement de la souris
    //sinon nous n'aurons l'information que si un bouton est enfoncé
    this->mouseTracking = true;
    setMouseTracking(this->mouseTracking);
    connect(this->b_toggleMouseTracking,SIGNAL(clicked()),this,SLOT(toggleMouseTracking()));
}

void mainWidget::keyPressEvent(QKeyEvent * event)
{
//liste des touches possibles, avec le type QT
//https://doc.qt.io/qt-5/qt.html#Key-enum

	if( event->key() == Qt::Key_A )
	{
		qDebug() << "clavier -> touche A" ;
	}
	else
		qDebug() << "clavier -> autre ->" << event->text();

	//permet de ne pas faire remonter ce message clavier aux classes parentes
	event->setAccepted(true);
}

void mainWidget::mouseMoveEvent(QMouseEvent *event)
{
	//(0,0) en haut à gauche du widget
	qDebug() << "souris -> déplacement (position locale) ->" << event->localPos();
}

void mainWidget::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "souris -> bouton pressé -> " << event->button();

}

void mainWidget::toggleMouseTracking(){
    if(this->mouseTracking){
        this->mouseTracking = false;
        setMouseTracking(this->mouseTracking);
        this->b_toggleMouseTracking->setText(QString("Activer le suivit souris"));
    }else{
        this->mouseTracking = true;
        setMouseTracking(this->mouseTracking);
        this->b_toggleMouseTracking->setText(QString("Désactiver le suivit souris"));
    }
}

mainWidget::~mainWidget()
{

}
