#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(this->ui->actionContact,SIGNAL(triggered()),this,SLOT(onQActionContactClicked()));
    connect(this->ui->actionInteraction,SIGNAL(triggered()),this,SLOT(onQActionInteractionClicked()));
}

void MainWindow::onContactFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData();

    QString contactFirstName = data.at("Prénom");
    QString contactLastName = data.at("Nom");
    QString contactEntreprise = data.at("Entreprise");
    QString contactEmail = data.at("Email");
    QString contactPhone = data.at("Téléphone");
    QString contactPhoto = data.at("Photo");
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

MainWindow::~MainWindow(){
    delete ui;

    if(!this->contactForm){
        delete this->contactForm;
    }

    if(!this->interactionForm){
        delete this->interactionForm;
    }
}
