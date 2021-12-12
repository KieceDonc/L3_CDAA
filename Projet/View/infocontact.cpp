#include "infocontact.h"
#include "ui_infocontact.h"
#include <QDateEdit>
#include <QDebug>
#include <QDir>
#include <QPlainTextEdit>
#include <QPushButton>

InfoContact::InfoContact(QWidget *parent, ContactID * c) :
    QWidget(parent),
    ui(new Ui::InfoContact)
{
    ui->setupUi(this);
    this->currentContact = c;
    this->ui->labelPhoto->setText(QDir::currentPath() );
    ui->lineFirstName->setText(QString::fromStdString(c->contact->getFirstName()));
    ui->lineLastName->setText(QString::fromStdString(c->contact->getLastName()));
    ui->lineEntreprise->setText(QString::fromStdString(c->contact->getEnterprise()));
    ui->lineMail->setText(QString::fromStdString(c->contact->getMail()));
    ui->linePhone->setText(QString::fromStdString(c->contact->getPhone()));
    ui->label_i->setFixedHeight((40));
    emit(displayInteractions());


}

void InfoContact::displayInteractions(){
    std::list<Interaction *> lst = this->currentContact->contact->getInteractions();

    if(!lst.empty()){

        std::list<Interaction *>::iterator it;
        qDebug() << QString::fromStdString(lst.front()->getContent());
        for(it = lst.begin() ; it != lst.end() ; it++){

            QHBoxLayout * qhb = new QHBoxLayout();
            QPushButton * b = new QPushButton();
            QDateEdit * ldate = new QDateEdit();
            QPlainTextEdit * lcont = new QPlainTextEdit();

            // Delete button properties
            b->setText("✕");
            b->setFixedWidth(20);
            b->setFixedHeight(20);

            // Date edit properties
            ldate->setDisplayFormat("dd-MM-yyyy");
            ldate->setDate(QDate::fromString(QString::fromStdString( (*it)->getDate().toString() )));

            // Todo content textedit properties
            lcont->appendPlainText( QString::fromStdString((*it)->getContent()));
            lcont->setMaximumHeight(50);
            qhb->addWidget(b);
            qhb->addWidget(ldate);
            qhb->addWidget(lcont);
            this->ui->interactionLayout->addLayout(qhb);
        }
    }
}

InfoContact::~InfoContact()
{
    delete ui;
}
