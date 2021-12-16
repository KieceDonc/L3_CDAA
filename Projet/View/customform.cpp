#include "customform.h"

#include <QFileDialog>

/**
 * @class CustomForm
 * <img src="../assets/CustomForm.png"><br>
 * <i>This is what a custom form with 6 parameters (First Name, Last Name...) looks like</i><br>
 * A custom form is a form that can be called passing a few QStrings as arguments to get different kinds of values.<br>
 * Although it was planned to have many uses...  We used it only once : To make a contact, when clicking on an action in the MainWindow.
 */

CustomForm::CustomForm(QWidget *parent) : QWidget(parent){

}

/**
 * <p></p>
 * @brief Fills the widget with all the different elements passed in parameter.
 * @param std::vector<QString>
 */
void CustomForm::init(std::vector<QString> fieldNameList){
    this->fieldNameList=fieldNameList;

    // on initialise le layout principal
    this->mainLayout = new QVBoxLayout();

    // On initialise le layout qui va contenir les champs a remplir
    this->fieldsLayout = new QFormLayout();
    this->fieldsLayout->setAlignment(Qt::AlignVertical_Mask);
    this->fieldsLayout->setSpacing(6);

    // On initialise la taille des vecteurs pour les objets QLabel et QLineEdit
    this->labelList.reserve(this->getSizeOfFieldNameList());
    this->lineEditList.reserve(this->getSizeOfFieldNameList());

    // On initialise chaque label / lineEdit et on l'ajoute au layout destiné à ces champs
    for(int index = 0; index < this->getSizeOfFieldNameList(); index++){
        QString currentFieldName = this->fieldNameList.at(index);

        this->labelList[index] = new QLabel();
        this->labelList[index]->setText(currentFieldName);

        this->lineEditList[index] = new QLineEdit();
        this->lineEditList[index]->setMinimumSize(300,25);

        this->fieldsLayout->addRow(this->labelList[index],this->lineEditList[index]);
    }

    // Initializing file dialog
    //QFileDialog * qf = new QFileDialog();

    // On initialise le bouton pour le choix d'une photo
    QPushButton * bPhoto = new QPushButton();
    bPhoto->setText("Chose a picture");
    connect(bPhoto,SIGNAL(clicked()),this,SLOT(onButtonPhotoClicked()));

    // On initialise le bouton ok
    this->pushButtonOK = new QPushButton();
    this->pushButtonOK->setText("OK");
    connect(this->pushButtonOK,SIGNAL(clicked()),this,SLOT(onButtonOkPush()));

    // On ajoute le layout des champs + le boutton ok au layout principal
    this->mainLayout->addItem(this->fieldsLayout);
    this->mainLayout->addWidget(this->pushButtonOK);
    this->mainLayout->addWidget(bPhoto);

    // Disabling photo field
    lineEditList[5]->setEnabled(false);

    // On décrit que le layout de ce widget est le mainLayout
    this->setLayout(this->mainLayout);

    this->show();
}

/**
 * <p></p>
 * @brief Retrieves the data inputed by the user.
 */
std::map<QString,QString> CustomForm::getData(){
    return this->data;
}

/**
 * <p></p>
 * @brief Gets the amount of fields.
 * @return int
 */
int CustomForm::getSizeOfFieldNameList(){
    return (int)(this->fieldNameList.size());
}

void CustomForm::onButtonOkPush(){

    bool canBeSend = true;

    for(int index = 0; index < this->getSizeOfFieldNameList(); index++){
        QLineEdit* currentLineEdit = this->lineEditList[index];
        QString currentText = currentLineEdit->text();
        if(currentText.size()==0 || currentText=="Please fill this field"){
            canBeSend = false;
            currentLineEdit->setText("Please fill this field.");
        }else{
            this->data[this->fieldNameList.at(index)]=currentText;
        }
    }

    if(canBeSend){
        emit onDataReady();
        this->close();
    }
}

/**
 * Slot running when the signal clicked() on the "Choose picture" button has been triggered..
 * Calls a QFileDialog with a filter to show .png and .jpg files only.
 * <img src="../assets/QFileDialogPhoto.png">
 * @brief Slot opening a dialog to select a picture.
 */
void CustomForm::onButtonPhotoClicked()
{
    fileDialog = new QFileDialog();
    //QStringList filters;
    fileDialog->setAttribute(Qt::WA_DeleteOnClose);
    fileDialog->setWindowModality(Qt::ApplicationModal);
    QString filter = "PNG File (*.png) ;; JPG File (*.jpg)";
    lineEditList[5]->setText(fileDialog->getOpenFileName(this,"Open file",QDir::homePath(),filter));
}

/**
 * <p></p>
 * @brief Basic destructor
 */
CustomForm::~CustomForm(){
    delete this->mainLayout;

    // delete this->fieldsLayout;

    for(int x =0; x < this->getSizeOfFieldNameList();x++){
        delete this->labelList[x];
        delete this->lineEditList[x];
    }

    delete this->pushButtonOK;
}
