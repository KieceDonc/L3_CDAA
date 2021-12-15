#include "jsonform.h"
#include "ui_jsonform.h"

JsonForm::JsonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonForm)
{
    ui->setupUi(this);
    connect(this->ui->buttonChoose,SIGNAL(clicked()),this,SLOT(onButtonChooseClicked()));
    this->ui->buttonOk->setEnabled(false);


}

void JsonForm::onButtonChooseClicked()
{
    this->fileDialog = new QFileDialog();
    fileDialog->setAttribute(Qt::WA_DeleteOnClose);
    fileDialog->setWindowModality(Qt::ApplicationModal);
    this->ui->linePath->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::homePath() , QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
    if(!this->ui->linePath->text().isEmpty())
        this->ui->buttonOk->setEnabled(true);
}

void JsonForm::onButtonOkClicked()
{
    emit makeJson(this->ui->linePath->text());
}

JsonForm::~JsonForm()
{
    delete ui;
}
