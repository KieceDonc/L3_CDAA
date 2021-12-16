#include "jsonform.h"
#include "ui_jsonform.h"

/**
 * @class JsonForm
 * Form that allows the user to navigate through his storage and pick a folder, then to export the application data as JSON file using JsonInterface.
 * <img src="../assets/JsonForm.png">
 */

/**
 * <p></p>
 * @brief Constructor turns the "Export as JSON" button off, since the user didn't chose directory yet.
 * @param
 */
JsonForm::JsonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonForm)
{
    ui->setupUi(this);
    connect(this->ui->buttonChoose,SIGNAL(clicked()),this,SLOT(onButtonChooseClicked()));
    connect(this->ui->buttonOk,SIGNAL(clicked()),this,SLOT(onButtonOkClicked()));
    this->ui->buttonOk->setEnabled(false);


}

/**
 * <p></p>
 * @brief Slot triggered when the button "Choose a directory" has been clicked. Opens a QFileDialog() so the user can choose a directory.
 * It only displays directories. It then enables the button "Export as JSON" so the user can click it.
 */
void JsonForm::onButtonChooseClicked()
{
    this->fileDialog = new QFileDialog();
    fileDialog->setAttribute(Qt::WA_DeleteOnClose);
    fileDialog->setWindowModality(Qt::ApplicationModal);
    this->ui->linePath->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::homePath() , QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
    if(!this->ui->linePath->text().isEmpty())
        this->ui->buttonOk->setEnabled(true);
}

/**
 * @brief Slot triggered when the button "Export as JSON" has been clicked. Emits the signal "Make JSON" with the path of the chosen directory. Connected to the MainWindow where it generates the JSON using the app data.
 */
void JsonForm::onButtonOkClicked()
{
    emit makeJson(this->ui->linePath->text());
}

/**
 * <p></p>
 * @brief Generic destructor.
 */
JsonForm::~JsonForm()
{
    delete ui;
}
