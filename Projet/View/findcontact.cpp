#include "findcontact.h"
#include "ui_findcontact.h"

FindContact::FindContact(QWidget *parent) : QWidget(parent), ui(new Ui::FindContact){
    this->ui->setupUi(this);

    this->ui->findByComboBox->addItem("Sans options");
    this->ui->findByComboBox->addItem("Prénom");
    this->ui->findByComboBox->addItem("Nom");
    this->ui->findByComboBox->addItem("Entreprise");
    this->ui->findByComboBox->addItem("Mail");
    this->ui->findByComboBox->addItem("Téléphone");
    this->ui->findByComboBox->addItem("Date");
    connect(this->ui->findByComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(onComboBoxItemChanged()));

    connect(this->ui->userInput,SIGNAL(textChanged(QString)),this,SLOT(onInputChanged()));

    this->model = new QStandardItemModel();
    this->ui->resultView->setModel(model);
    this->ui->resultView->setSortingEnabled(true);


    this->currentAttribute=0;
    loadListOfContact();
    updateResultView();
}

void FindContact::updateResultView(){
    this->model->clear();

    this->model->setHorizontalHeaderItem(0, new QStandardItem("Prénom"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("Entreprise"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("Mail"));
    this->model->setHorizontalHeaderItem(4, new QStandardItem("Téléphone"));
    this->model->setHorizontalHeaderItem(5, new QStandardItem("Date"));

    QList<QStandardItem*> rowData;
    std::list<ContactID>::iterator it;

    for (it = this->loadedContacts.begin(); it != this->loadedContacts.end(); ++it){
        Contact* contact = it->contact;

        bool shouldBeShow = false;

        // We check if current attribute of contact contain user input so we can show it
        if(this->currentAttributeValue.length()==0){
            shouldBeShow = true;
        }else{
            std::string toCompare;
            switch(this->currentAttribute){
                case 0:{ // Without option
                    toCompare = contact->getFirstName();
                    toCompare+= contact->getLastName();
                    toCompare+= contact->getEnterprise();
                    toCompare+= contact->getMail();
                    toCompare+= contact->getPhone();
                    toCompare+= contact->getDateOfCreation().toString();
                    break;
                }
                case 1:{ // FirstName
                    toCompare = contact->getFirstName();
                    break;
                }
                case 2:{ // LastName
                    toCompare = contact->getLastName();
                    break;
                }
                case 3:{ // Enterprise
                    toCompare = contact->getEnterprise();
                    break;
                }
                case 4:{ // Mail
                    toCompare = contact->getMail();
                    break;
                }
                case 5:{ // Phone
                    toCompare = contact->getPhone();
                    break;
                }
                case 6:{ // DateOfCreation
                    toCompare = contact->getDateOfCreation().toString();
                    break;
                }
                default:{
                    qDebug() << "Error findcontact, currentAttribute out of bounds, currentAttribute =  " << this->currentAttribute;
                }
            }
            std::transform(toCompare.begin(), toCompare.end(), toCompare.begin(), ::tolower); // lower toCompare
            shouldBeShow = toCompare.find(this->currentAttributeValue) != std::string::npos;
        }

        if(shouldBeShow){
            rowData.clear();
            rowData << new QStandardItem(QString::fromUtf8(contact->getFirstName().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getLastName().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getEnterprise().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getMail().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getPhone().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getDateOfCreation().toString().c_str()));
            model->appendRow(rowData);
        }
    }
}

void FindContact::onContactListUpdate(){
    this->deleteContact();
    this->loadListOfContact();
    this->updateResultView();
}

void FindContact::onComboBoxItemChanged(){
    this->currentAttribute = this->ui->findByComboBox->currentIndex();
    this->updateResultView();
}

void FindContact::onInputChanged(){
    this->currentAttributeValue=this->ui->userInput->text().toStdString();
    std::transform(this->currentAttributeValue.begin(), this->currentAttributeValue.end(), this->currentAttributeValue.begin(), ::tolower); // lower input

    this->updateResultView();
}

void FindContact::loadListOfContact(){
    this->sqli.getAllContacts(this->loadedContacts);
}

void FindContact::deleteContact(){
    std::list<ContactID>::iterator it;
    for (it = this->loadedContacts.begin(); it != this->loadedContacts.end(); ++it){
        delete it->contact;
    }
}

FindContact::~FindContact(){
    deleteContact();
    delete this->ui;
    delete this->model;
}
