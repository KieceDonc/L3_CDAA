#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findcontact.h"
#include "jsonform.h"

#include <Others/jsoninterface.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);


    // Initializing the contacts list with sql interface
    this->loadedContacts = std::list<ContactID>();
    this->mapInteractionTodo = MapInteractionTodo();
    this->loadContacts();

    // Connecting actions
    connect(this->ui->actionContact,SIGNAL(triggered()),this,SLOT(onQActionContactClicked()));
    connect(this->ui->actionDisplayInteractions,SIGNAL(triggered()),this,SLOT(onDisplayInteractionClicked()));
    connect(this->ui->actionExport_JSON,SIGNAL(triggered()),this,SLOT(onActionExportJsonClicked()));




    findcontact = new FindContact(this);
    this->findcontact->mp = &(this->mapInteractionTodo);
    this->ui->middleLayout->addWidget(findcontact);
    findcontact->init(&this->loadedContacts);
    connect(this,SIGNAL(onContactListUpdate()),this->findcontact,SLOT(onContactListUpdate()));

    makeJson();


}

void MainWindow::onContactFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData();

    QString contactFirstName = data.at("Prénom");
    QString contactLastName = data.at("Nom");
    QString contactEntreprise = data.at("Entreprise");
    QString contactEmail = data.at("Email");
    QString contactPhone = data.at("Téléphone");
    QString contactPhoto = data.at("Photo");

    Contact c = Contact(contactFirstName.toStdString(),contactLastName.toStdString(),contactEntreprise.toStdString(),contactEmail.toStdString(),contactPhone.toStdString(),contactPhoto.toStdString(),Date());
    this->sqli.insertContact(c,&(this->loadedContacts));

    this->loadedContacts = std::list<ContactID>();
    this->loadContacts();

    emit onContactListUpdate();
    //this->refreshContactList();
}


void MainWindow::onQActionContactClicked(){
    if(!this->contactForm)
        delete this->contactForm;
    this->contactForm = new CustomForm();
    contactForm->setAttribute(Qt::WA_DeleteOnClose);
    contactForm->setWindowModality(Qt::ApplicationModal);
    connect(this->contactForm,SIGNAL(onDataReady()),this,SLOT(onContactFormComplete()));
    this->contactForm->init({"Prénom","Nom","Entreprise","Email","Téléphone","Photo"});

    //this->setCentralWidget(this->contactForm);
    this->currentForm = this->contactForm;
}

void MainWindow::onActionExportJsonClicked(){
    JsonForm * jsf = new JsonForm();
    jsf->show();
}

void MainWindow::onDisplayInteractionClicked(){
    InfoInteractions * ii = new InfoInteractions(nullptr,&(this->loadedContacts),&(this->mapInteractionTodo));
    ii->setAttribute(Qt::WA_DeleteOnClose);
    ii->setWindowModality(Qt::ApplicationModal);
    ii->show();
}

void MainWindow::loadContacts(){
    this->sqli.getAllContacts(this->loadedContacts, this->mapInteractionTodo);
    auto l_front = loadedContacts.begin();
    std::advance(l_front,1);
    emit onContactListUpdate();
}

/*void MainWindow::refreshContactList(){
    this->ui->contactList->clear();
    for(std::list<ContactID>::iterator it = loadedContacts.begin() ; it != loadedContacts.end() ; it++ )
        this->ui->contactList->addItem(QString::fromStdString(it->contact->getLastName()+" "+it->contact->getFirstName()));

}*/

MainWindow::~MainWindow(){
    delete ui;
    if(!this->contactForm)
        delete this->contactForm;
    if(!this->interactionForm)
        delete this->interactionForm;

}

void MainWindow::makeJson()
{
    /*JSONInterface jsi = JSONInterface();
    jsi.addContact(&(this->loadedContacts));
    jsi.writeInFile("/home/stinky/Bureau","test");*/
}
