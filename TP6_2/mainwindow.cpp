#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->contactForm = ui->contactForm;
    this->setCentralWidget(this->contactForm);
}

MainWindow::~MainWindow()

{
    delete ui;
}
