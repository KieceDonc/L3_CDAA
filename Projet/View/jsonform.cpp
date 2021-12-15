#include "jsonform.h"
#include "ui_jsonform.h"

JsonForm::JsonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonForm)
{
    ui->setupUi(this);
    connect(this->ui->buttonChoose,SIGNAL(clicked()),this,SLOT(onButtonChooseClicked()));


}

JsonForm::~JsonForm()
{
    delete ui;
}

void JsonForm::onButtonChooseClicked()
{
    this->fileDialog = new QFileDialog();
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setOption(QFileDialog::ShowDirsOnly);
    fileDialog->setAttribute(Qt::WA_DeleteOnClose);
    fileDialog->setWindowModality(Qt::ApplicationModal);
    fileDialog->show();

}
