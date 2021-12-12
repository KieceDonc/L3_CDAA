#include "infocontact.h"
#include "ui_infocontact.h"
#include <QDir>

InfoContact::InfoContact(QWidget *parent, ContactID * c) :
    QWidget(parent),
    ui(new Ui::InfoContact)
{
    ui->setupUi(this);
    this->ui->labelPhoto->setText(QDir::currentPath() );
}

InfoContact::~InfoContact()
{
    delete ui;
}
