#include "infocontact.h"
#include "ui_infocontact.h"

InfoContact::InfoContact(QWidget *parent, Contact * c) :
    QWidget(parent),
    ui(new Ui::InfoContact)
{
    ui->setupUi(this);
}

InfoContact::~InfoContact()
{
    delete ui;
}
