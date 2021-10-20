#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->buttonAlreadyClicked = false;
    ui->menuBar->addAction(ui->actionA_propos);
    connect(ui->actionA_propos, SIGNAL(triggered(bool)), this, SLOT(slot_aPropos()));
    connect(ui->actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    this->qTimer = new QTimer(this);
    connect(this->qTimer, SIGNAL(timeout()), this, SLOT(updateQTimer()));
    this->qTimer->start(1000);
}

MainWindow::~MainWindow(){
    delete ui;
    if(this->personne !=nullptr){
        delete this->personne;
    }
    delete this->qTimer;
}

void MainWindow::on_pushButton_clicked(){
    if(!this->buttonAlreadyClicked){
        this->buttonAlreadyClicked = true;
        QString firstName = ui->prNomLineEdit->text();
        QString lastName = ui->nomLineEdit->text();
        QString birthdate = ui->dateDeNaissanceLineEdit->text();
        QString ville = ui->villeLineEdit->text();
        this->personne = new Personne(firstName,lastName,birthdate,ville);
    }else{
        QString toShow = "Firstname = "+this->personne->getFirstName()
                + "\nLastname = "+this->personne->getLastName()
                + "\nbirthdate = " + this->personne->getBirthdate()
                + "\nville = " + this->personne->getVille();

        ui->resultText->append(toShow);
    }
}

void MainWindow::slot_aPropos(){
    QMessageBox * messageAbout = new QMessageBox();
    messageAbout->about(this, "A propos",
    "Cette magnifique application a été créée\navec QtDesigner.");
    delete messageAbout;
}

void MainWindow::updateQTimer(){
    QTime timeValue;
    timeValue=QTime::currentTime();
    QString format="H:m:s.z";
    this->ui->timerLabel->setText (timeValue.toString (format));
}
