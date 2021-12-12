#include "findcontact.h"
#include "ui_findcontact.h"

FindContact::FindContact(QWidget *parent) : QWidget(parent), ui(new Ui::FindContact){
    this->ui->setupUi(this);

    // Sorting combobox creation
    this->ui->findByComboBox->addItem("No option");
    this->ui->findByComboBox->addItem("First Name");
    this->ui->findByComboBox->addItem("Last Name");
    this->ui->findByComboBox->addItem("Entreprise");
    this->ui->findByComboBox->addItem("Mail");
    this->ui->findByComboBox->addItem("Phone");
    this->ui->findByComboBox->addItem("Date");

    // Setting tableview behaviour
    this->ui->resultView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->resultView->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->ui->resultView->setSelectionMode( QAbstractItemView::SingleSelection );
    this->ui->resultView->verticalHeader()->hide();
    connect(this->ui->findByComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(onComboBoxItemChanged()));
    connect(this->ui->userInput,SIGNAL(textChanged(QString)),this,SLOT(onInputChanged()));
    connect(this->ui->resultView,SIGNAL(clicked(const QModelIndex &)),this,SLOT(onResultViewClicked(const QModelIndex &)));
    connect(this->ui->buttonClear,SIGNAL(clicked()),this,SLOT(onClearClicked()));

    // Setting calendar widget to pickdates
    qc = new QCalendarWidget();
    this->ui->lineDate1->setText("01-01-1970");
    this->ui->lineDate2->setText("31-12-2500");
    connect(this->ui->buttonDate1,SIGNAL(clicked()),this,SLOT(pickDateBegin()));
    connect(this->ui->buttonDate2,SIGNAL(clicked()),this,SLOT(pickDateEnd()));
    connect(qc,SIGNAL(selectionChanged()),this,SLOT(setDate()));

    // Setting sorting system
    this->model = new QStandardItemModel();
    this->ui->resultView->setModel(model);
    this->ui->resultView->setSortingEnabled(true);

    // Disabling more info button
    this->ui->buttonInfo->setEnabled(false);

    // More information button connect
    connect(this->ui->buttonInfo,SIGNAL(clicked()),this,SLOT(onMoreInfoClicked()));

    this->currentAttribute=0;

    loadListOfContact();
    updateResultView();

}

void FindContact::updateResultView(){
    this->model->clear();

    this->model->setHorizontalHeaderItem(0, new QStandardItem("First Name"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("Last Name"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("Entreprise"));
    this->model->setHorizontalHeaderItem(3, new QStandardItem("Mail"));
    this->model->setHorizontalHeaderItem(4, new QStandardItem("Phone"));
    this->model->setHorizontalHeaderItem(5, new QStandardItem("Date"));
    this->model->setHorizontalHeaderItem(6, new QStandardItem("ID"));
    this->ui->resultView->hideColumn(6);

    QList<QStandardItem*> rowData;
    std::list<ContactID>::iterator it;

    QDate begin(QDate::fromString(this->ui->lineDate1->text(),QString("dd-MM-yyyy")));
    QDate end(QDate::fromString(this->ui->lineDate2->text(),QString("dd-MM-yyyy")));

    for (it = this->loadedContacts.begin(); it != this->loadedContacts.end(); ++it){
        Contact* contact = it->contact;
        int id = it->id;

        bool shouldBeShow = false;

        //First we check is the date is in the correct range. If not, no need to do the following.
        QString contactDateString(QString::fromStdString(contact->getDateOfCreation().toString()));
        QDate contactDate(QDate::fromString(contactDateString,"dd-MM-yyyy"));

        if(contactDate < end && contactDate > begin){
            // We check if current attribute of contact contain user input so we can show it
            if(this->currentAttributeValue.length()==0)
                shouldBeShow = true;
            else{
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
        }

        if(shouldBeShow){
            rowData.clear();
            rowData << new QStandardItem(QString::fromUtf8(contact->getFirstName().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getLastName().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getEnterprise().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getMail().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getPhone().c_str()));
            rowData << new QStandardItem(QString::fromUtf8(contact->getDateOfCreation().toString().c_str()));
            rowData << new QStandardItem(QString::number(id));
            model->appendRow(rowData);
        }
    }
}

void FindContact::onContactListUpdate(){
    this->deleteContact();
    this->loadListOfContact();
    this->updateResultView();
}

void FindContact::pickDateBegin()
{
    qc->setMinimumDate( QDate::fromString("01-01-1970",QString("dd-MM-yyyy") ) );
    qc->setMaximumDate( QDate::fromString("31-12-2500",QString("dd-MM-yyyy") ) );
    currentQLE = this->ui->lineDate1;
    qc->show();
}

void FindContact::pickDateEnd()
{
    currentQLE = this->ui->lineDate2;

    if(!this->ui->lineDate1->text().toStdString().empty())
        qc->setMinimumDate( QDate::fromString(this->ui->lineDate1->text(),QString("dd-MM-yyyy") ) );
    qc->show();
}

void FindContact::setDate()
{

    currentQLE->setText(qc->selectedDate().toString("dd-MM-yyyy"));

    if(QDate::fromString(this->ui->lineDate1->text(),QString("dd-MM-yyyy")) > QDate::fromString(this->ui->lineDate2->text(),QString("dd-MM-yyyy")))
        this->ui->lineDate2->setText(this->ui->lineDate1->text());

    updateResultView();
}

void FindContact::onResultViewClicked(const QModelIndex &index)
{
    QString cellText = index.data().toString();
    QAbstractItemModel *model = ui->resultView->model();
    int i = model->index(index.row(), 6).data().toString().toInt();
    std::list<ContactID>::iterator it;

    for (it = this->loadedContacts.begin(); it != this->loadedContacts.end(); ++it) {
        if(it->id == i){
            selectedContact = &(*it);
            break;
        }
    }
    this->ui->buttonInfo->setEnabled(true);
}

void FindContact::onClearClicked()
{
    this->ui->resultView->clearSelection();
    this->selectedContact = nullptr;
    this->ui->buttonInfo->setEnabled(false);
}

void FindContact::onMoreInfoClicked()
{
    InfoContact * ic = new InfoContact(nullptr,this->selectedContact);
    ic->show();
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