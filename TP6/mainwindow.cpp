#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextBlock"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_valider_clicked(){
    QStringList* listOfTodo = new QStringList();
    QTextDocument* textDocument = this->ui->textEdit->document();
    QTextCursor c(textDocument);

    QTextDocument::FindFlag fcs = (QTextDocument::FindFlag) 0;
    while(!c.isNull()){
        c = textDocument->find("@todo",c.position(),fcs);
        if(!c.isNull()){
            QTextBlock qtb = c.block();
            listOfTodo->append(qtb.text());
            qDebug() << qtb.text();
        }
    }
}
