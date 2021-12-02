#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(this->ui->actionContact,SIGNAL(triggered()),this,SLOT(onQActionContactClicked()));
    connect(this->ui->actionInteraction,SIGNAL(triggered()),this,SLOT(onQActionInteractionClicked()));
}

void MainWindow::onFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData()
            ;
    for(auto it = data.cbegin(); it != data.cend(); ++it){
        qDebug() << it->first << " : " << it->second << "\n";
    }
}

void MainWindow::onQActionContactClicked(){
    if(!this->contactForm){
        delete this->contactForm;
    }

    this->contactForm = new CustomForm();
    connect(this->contactForm,SIGNAL(onDataReady()),this,SLOT(onFormComplete()));
    this->contactForm->init({"Nom","Entreprise","Email"});

    this->setCentralWidget(this->contactForm);
    this->currentForm = this->contactForm;
}

void MainWindow::onQActionInteractionClicked(){
    if(!this->interactionForm){
        delete this->interactionForm;
    }

    this->interactionForm = new CustomForm();
    connect(this->interactionForm,SIGNAL(onDataReady()),this,SLOT(onFormComplete()));
    this->interactionForm->init({"Nom","Contenu"});

    this->setCentralWidget(this->interactionForm);
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
