#include "customform.h"

CustomForm::CustomForm(QWidget *parent) : QWidget(parent){

}

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

        this->fieldsLayout->addRow(this->labelList[index],this->lineEditList[index]);
    }

    // On initialise le bouton ok
    this->pushButtonOK = new QPushButton();
    this->pushButtonOK->setText("OK");
    connect(this->pushButtonOK,SIGNAL(clicked()),this,SLOT(onButtonOkPush()));

    // On ajoute le layout des champs + le boutton ok au layout principal
    this->mainLayout->addItem(this->fieldsLayout);
    this->mainLayout->addWidget(this->pushButtonOK);

    // On décrit que le layout de ce widget est le mainLayout
    this->setLayout(this->mainLayout);
}
std::map<QString,QString> CustomForm::getData(){
    return this->data;
}

int CustomForm::getSizeOfFieldNameList(){
    return (int)(this->fieldNameList.size());
}

void CustomForm::onButtonOkPush(){

    bool canBeSend = true;

    for(int index = 0; index < this->getSizeOfFieldNameList(); index++){
        QLineEdit* currentLineEdit = this->lineEditList[index];
        QString currentText = currentLineEdit->text();
        if(currentText.size()==0 || currentText=="Vous devez compléter cette information"){
            canBeSend = false;
            currentLineEdit->setText("Vous devez compléter cette information");
        }else{
            this->data[this->fieldNameList.at(index)]=currentText;
        }
    }

    if(canBeSend){
        this->onDataReady();
    }
}

CustomForm::~CustomForm(){
    delete this->mainLayout;

    // delete this->fieldsLayout;

    for(int x =0; x < this->getSizeOfFieldNameList();x++){
        delete this->labelList[x];
        delete this->lineEditList[x];
    }

    delete this->pushButtonOK;
}
