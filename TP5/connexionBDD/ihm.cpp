#include "ihm.h"
#include "ui_ihm.h"

ihm::ihm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ihm)
{
    ui->setupUi(this);
}

ihm::~ihm()
{
    delete ui;
}
