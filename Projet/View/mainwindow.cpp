#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findcontact.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);


    // Initialisation de la liste de contacts et de l'interface sql
    this->loadedContacts = std::list<ContactID>();

    connect(this->ui->actionContact,SIGNAL(triggered()),this,SLOT(onQActionContactClicked()));
    connect(this->ui->actionInteraction,SIGNAL(triggered()),this,SLOT(onQActionInteractionClicked()));



    this->loadContacts();
    //this->refreshContactList();

    findcontact = new FindContact(this);
    this->ui->middleLayout->addWidget(findcontact);
    findcontact->init(&this->loadedContacts);
    connect(this,SIGNAL(onContactListUpdate()),this->findcontact,SLOT(onContactListUpdate()));

}

void MainWindow::onContactFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData();

    QString contactFirstName = data.at("Prénom");
    QString contactLastName = data.at("Nom");
    QString contactEntreprise = data.at("Entreprise");
    QString contactEmail = data.at("Email");
    QString contactPhone = data.at("Téléphone");
    QString contactPhoto = data.at("Photo");

    Contact c(contactFirstName.toStdString(),contactLastName.toStdString(),contactEntreprise.toStdString(),contactEmail.toStdString(),contactPhone.toStdString(),Photo());
    this->sqli.insertContact(c,&(this->loadedContacts));
    emit onContactListUpdate();
    //this->refreshContactList();
}

void MainWindow::onInteractionFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData();

    QString contactFirstName = data.at("Date");

}

void MainWindow::onQActionContactClicked(){
    if(!this->contactForm){
        delete this->contactForm;
    }

    this->contactForm = new CustomForm();
    connect(this->contactForm,SIGNAL(onDataReady()),this,SLOT(onContactFormComplete()));
    this->contactForm->init({"Prénom","Nom","Entreprise","Email","Téléphone","Photo"});

    //this->setCentralWidget(this->contactForm);
    this->currentForm = this->contactForm;
}

void MainWindow::onQActionInteractionClicked(){
    if(!this->interactionForm){
        delete this->interactionForm;
    }

    this->interactionForm = new CustomForm();
    connect(this->interactionForm,SIGNAL(onDataReady()),this,SLOT(onInteractionFormComplete()));
    this->interactionForm->init({"Date","Contenu"});

    this->currentForm = this->interactionForm;
}

void MainWindow::loadContacts(){
    this->sqli.getAllContacts(this->loadedContacts);
    emit onContactListUpdate();
}

/*void MainWindow::refreshContactList(){
    this->ui->contactList->clear();
    for(std::list<ContactID>::iterator it = loadedContacts.begin() ; it != loadedContacts.end() ; it++ )
        this->ui->contactList->addItem(QString::fromStdString(it->contact->getLastName()+" "+it->contact->getFirstName()));

}*/

MainWindow::~MainWindow(){
    delete ui;

    if(!this->contactForm){
        delete this->contactForm;
    }

    if(!this->interactionForm){
        delete this->interactionForm;
    }
}
