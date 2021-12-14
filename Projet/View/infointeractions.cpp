#include "infointeractions.h"
#include "mainwindow.h"
#include "ui_infointeractions.h"

#include <QDate>

InfoInteractions::InfoInteractions(QWidget *parent,std::list<ContactID> * lst, MapInteractionTodo * map) :
    QWidget(parent),
    ui(new Ui::InfoInteractions)
{
    ui->setupUi(this);

    connect(this->ui->buttonSwitch,SIGNAL(clicked()),this,SLOT(fillTodos()));

    this->loadedContacts = lst;
    this->mapInterationTodo = map;


    this->fillInteractions();

}

InfoInteractions::~InfoInteractions()
{
    delete ui;
}

void InfoInteractions::fillInteractions()
{
    int taille = this->loadedContacts->size();
    std::list<ContactID> * lstContacts = this->loadedContacts;
    this->viewInteractions = new QTableWidget(taille,4);
    this->viewInteractions->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->viewInteractions->setRowCount(0);

    QStringList labels;
    labels << "First name" << "Last Name" << "Date" << "Interaction";
    this->viewInteractions->setHorizontalHeaderLabels(labels);



    int rowIndex = 0;
    std::list<ContactID>::iterator itContact;
    std::list<Interaction*>::iterator itInteraction;
    for(itContact = lstContacts->begin() ; itContact != lstContacts->end() ; itContact++){
        std::list<Interaction *> lstInteractions = (*itContact).contact->getInteractions();
        for(itInteraction = lstInteractions.begin(); itInteraction != lstInteractions.end() ; itInteraction++){
                QDate date = QDate::fromString(QString::fromStdString((*itInteraction)->getDate().toString()),"dd-MM-yyyy");
                QTableWidgetItem * itemFirstName = new QTableWidgetItem(QString::fromStdString((*itContact).contact->getFirstName()));
                QTableWidgetItem * itemLastName = new QTableWidgetItem(QString::fromStdString((*itContact).contact->getLastName()));
                QTableWidgetItem * itemDate = new QTableWidgetItem();
                QTableWidgetItem * itemContent = new QTableWidgetItem(QString::fromStdString((*itInteraction)->getContent()));
                itemDate->setData(Qt::DisplayRole, date);
                this->viewInteractions->insertRow(rowIndex);
                this->viewInteractions->setItem(rowIndex,0,itemFirstName);
                this->viewInteractions->setItem(rowIndex,1,itemLastName);
                this->viewInteractions->setItem(rowIndex,2,itemDate);
                this->viewInteractions->setItem(rowIndex,3,itemContent);
                rowIndex++;
        }
    }

    this->ui->viewLayout->addWidget(this->viewInteractions);

}

void InfoInteractions::fillTodos()
{
    qDebug() << "test";
    int taille = this->loadedContacts->size();
    std::list<ContactID> * lstContacts = this->loadedContacts;
    this->viewTodos = new QTableWidget(0,4);
    this->viewTodos->setRowCount(0);

    QStringList labels;
    labels << "First name" << "Last Name" << "Date" << "Interaction";
    //this->viewInteractions->setHorizontalHeaderLabels(labels);



    int rowIndex = 0;
    std::list<ContactID>::iterator itContact;
    std::list<Interaction*>::iterator itInteraction;
    std::list<Todo *>::iterator itTodo;

    for(itContact = lstContacts->begin() ; itContact != lstContacts->end() ; itContact++){
        std::list<Interaction *> lstInteractions = (*itContact).contact->getInteractions();
        for(itInteraction = lstInteractions.begin(); itInteraction != lstInteractions.end() ; itInteraction++){

            // If the map has a key and if this key is not an empty list, then add the todos to the list
            if(this->mapInterationTodo->hasKey(*itInteraction) && !( this->mapInterationTodo->at(*itInteraction).empty() ) ){
                std::list<Todo *> lstTodos = this->mapInterationTodo->at(*itInteraction);
                for(itTodo = lstTodos.begin(); itTodo != lstTodos.end() ; itTodo++){
                    qDebug() << QString::fromStdString((*itTodo)->getDate().toString());
                    QDate date = QDate::fromString(QString::fromStdString((*itTodo)->getDate().toString()),"dd-MM-yyyy");
                    QTableWidgetItem * itemFirstName = new QTableWidgetItem(QString::fromStdString((*itContact).contact->getFirstName()));
                    QTableWidgetItem * itemLastName = new QTableWidgetItem(QString::fromStdString((*itContact).contact->getLastName()));
                    QTableWidgetItem * itemDate = new QTableWidgetItem();
                    QTableWidgetItem * itemContent = new QTableWidgetItem(QString::fromStdString((*itTodo)->getContent()));
                    itemDate->setData(Qt::DisplayRole, date);
                    this->viewTodos->insertRow(rowIndex);
                    this->viewTodos->setItem(rowIndex,0,itemFirstName);
                    this->viewTodos->setItem(rowIndex,1,itemLastName);
                    this->viewTodos->setItem(rowIndex,2,itemDate);
                    this->viewTodos->setItem(rowIndex,3,itemContent);
                    rowIndex++;
                }
            }
        }
    }

    this->ui->viewLayout->replaceWidget(this->viewInteractions,this->viewTodos);

}

void InfoInteractions::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    int size0 = 100;
    int size1 =  this->viewInteractions->width()*3-size0;

    this->viewInteractions->setColumnWidth(0, size0);
    this->viewInteractions->setColumnWidth(1, size0);
    this->viewInteractions->setColumnWidth(2, size0);
    this->viewInteractions->setColumnWidth(3, size1);

}


