#include "infointeractions.h"
#include "mainwindow.h"
#include "ui_infointeractions.h"

#include <QDate>

/**
 * @class InfoInteractions
 * This window allows the user to view, sort (by clicking on the columns), and search (from keywords or between two dates) interactions or todos in QTableWidgets, like in a spreadsheet.<br>
 * This operation is read only, and pretty fast since no query is made to the Database. The QTableWidget has great methods, espacially for sorting.<br>
 * Switching between Todos and Interactions can be done by clicking on the button at the bottom of the window.
 * <img src="../assets/DisplayInteractions.png">
 */

/**
 * <p></p>
 * @brief Constructor taking a ContactID list and a MapInteractionTodo maping their interactions. Calls the functions fillInteractions and fillTodos to fill the QTableWidgets.
 * @param std::list<ContactID>
 * @param MapInteractionTodo
 */
InfoInteractions::InfoInteractions(QWidget *parent,std::list<ContactID> * lst, MapInteractionTodo * map) :
    QWidget(parent),
    ui(new Ui::InfoInteractions)
{
    ui->setupUi(this);

    connect(this->ui->buttonSwitch,SIGNAL(clicked()),this,SLOT(switchViews()));
    this->ui->buttonSwitch->setText("Switch for Todos");
    this->loadedContacts = lst;
    this->mapInterationTodo = map;


    this->ui->dateEdit1->setDate(QDate::fromString("01-01-1970","dd-MM-yyyy"));
    this->ui->dateEdit2->setDate(QDate::fromString("31-12-2500","dd-MM-yyyy"));
    connect(this->ui->dateEdit1,SIGNAL(editingFinished()),this,SLOT(sortViews()));
    connect(this->ui->dateEdit2,SIGNAL(editingFinished()),this,SLOT(sortViews()));
    connect(this->ui->lineFirstName,SIGNAL(textChanged(QString)),this,SLOT(sortViews()));
    connect(this->ui->lineLastName,SIGNAL(textChanged(QString)),this,SLOT(sortViews()));
    connect(this->ui->lineContent,SIGNAL(textChanged(QString)),this,SLOT(sortViews()));
    connect(this,SIGNAL(triggerSortViews()),this,SLOT(sortViews()));


    this->fillInteractions();
    this->fillTodos();
    this->ui->viewLayout->addWidget(this->viewInteractions);

    this->ui->viewLayout->addWidget(this->viewInteractions);
    this->ui->viewLayout->addWidget(this->viewTodos);
    this->viewTodos->hide();
    this->viewInteractions->show();



}

/**
 * <p></p>
 * @brief Generic destructor.
 */
InfoInteractions::~InfoInteractions()
{
    delete ui;
}

/**
 * @brief Fills the viewInteractions QTableWidget with every interactions from every contacts. Also displays the first name and last name of its owner.
 */
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
    this->viewInteractions->setSortingEnabled(true);

}

/**
 * <p></p>
 * @brief Fills the viewTodos QTableWidget with every todos from every interactions (in the MapInteractionTodo) from every contacts. Also displays the first name and last name of its owner.
 */
void InfoInteractions::fillTodos()
{
    std::list<ContactID> * lstContacts = this->loadedContacts;
    this->viewTodos = new QTableWidget(0,4);
    this->viewTodos->setRowCount(0);
    this->viewTodos->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QStringList labels;
    labels << "First name" << "Last Name" << "Date" << "Todo";
    this->viewTodos->setHorizontalHeaderLabels(labels);



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
    this->viewTodos->setSortingEnabled(true);
}


/**
 * <p></p>
 * @brief Switches the displayed widget between viewTodos and viewInteractions. Sets their size to the current window, and emits a triggerSortViews signal to sort.
 */
void InfoInteractions::switchViews()
{
    if(this->ui->buttonSwitch->text() == "Switch for Todos"){
        this->ui->buttonSwitch->setText("Switch for Interactions");
        this->viewInteractions->hide();
        this->viewTodos->show();
        this->resize(this->geometry().width(), this->geometry().height());
    }else{
        this->ui->buttonSwitch->setText("Switch for Todos");
        this->viewTodos->hide();
        this->viewInteractions->show();
        this->resize(this->geometry().width(), this->geometry().height());
    }

    emit triggerSortViews();
}

/**
 * Loops over each QTableWidget elements, checking if they should be displayed. If not, hides them.
 * @brief Sorts the current view according to criterias : LineEdits and 2 dates.
 */
void InfoInteractions::sortViews()
{
    QTableWidget * view;
    if(this->ui->buttonSwitch->text() == "Switch for Todos")
        view = this->viewInteractions;
    else
        view = this->viewTodos;

    QDate dateBegin = this->ui->dateEdit1->date();
    QDate dateEnd = this->ui->dateEdit2->date();
    QString firstNameLine(this->ui->lineFirstName->text());
    QString lastNameLine(this->ui->lineLastName->text());
    QString contentLine(this->ui->lineContent->text());

    int rowCount = view->rowCount();

    for(int index = 0 ; index < rowCount ; index++){

        QString firstName = view->item(index,0)->text();
        QString lastName = view->item(index,1)->text();
        QString content = view->item(index,3)->text();
        QDate date = QDate::fromString(view->item(index,2)->text(),"yyyy-MM-dd");

        bool isFirstNameOk = ( firstNameLine == "" ) || ( firstName.contains(firstNameLine , Qt::CaseInsensitive) ) ;
        bool isLastNameOk = ( lastNameLine == "" ) || ( lastName.contains(lastNameLine , Qt::CaseInsensitive) ) ;
        bool isContent = ( contentLine == "" ) || ( content.contains(contentLine , Qt::CaseInsensitive) ) ;

        if(date > dateBegin && date < dateEnd && isFirstNameOk && isLastNameOk && isContent )
            view->showRow(index);
        else
            view->hideRow(index);


    }
}

/**
 * <p></p>
 * @brief Called when the window is resized. Ensures the content column is always large enough.
 * @param event
 */
void InfoInteractions::resizeEvent(QResizeEvent *event){
    int size0 = 100;
    int size1;
    if(this->ui->buttonSwitch->text() == "Switch for Todos")
        size1 =  this->viewInteractions->width()-(3*size0)-20;
    else
        size1 =  this->viewTodos->width()-(3*size0)-20;

    this->viewInteractions->setColumnWidth(0, size0);
    this->viewInteractions->setColumnWidth(1, size0);
    this->viewInteractions->setColumnWidth(2, size0);
    this->viewInteractions->setColumnWidth(3, size1);
    this->viewTodos->setColumnWidth(0, size0);
    this->viewTodos->setColumnWidth(1, size0);
    this->viewTodos->setColumnWidth(2, size0);
    this->viewTodos->setColumnWidth(3, size1);
}


