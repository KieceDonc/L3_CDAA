#include "findcontact.h"
#include "ui_findcontact.h"

#include <QTableWidgetItem>

/**
  * @class FindContact
  * Main widget for the MainWindow.
  * Displays all the contacts in a QTableView.<br>
  * Allows sorting by clicking on the table columns name.<br>
  * Keyword-based search on each contact attribute, case insensitive.<br>
  * Allows to pick 2 dates to sort contact.<br><br>
  * Different buttons allow 3 actions : Editing a contact, deleting one, and clearing the QTableView selection.
  * <img src="../assets/FindContact.png">
  */

/**
 * Adds the combo box, the QLineEdits, the QCalendarWidget to pick the dates.
 * @brief FindContact constructor sets up the frame by adding the widgets and connecting the different signals and slots.
 * @param parent
 */
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
    this->ui->resultView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(this->ui->findByComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(onComboBoxItemChanged()));
    connect(this->ui->userInput,SIGNAL(textChanged(QString)),this,SLOT(onInputChanged()));
    connect(this->ui->resultView,SIGNAL(clicked(const QModelIndex &)),this,SLOT(onResultViewClicked(const QModelIndex &)));
    connect(this->ui->buttonClear,SIGNAL(clicked()),this,SLOT(onClearClicked()));

    // Delete contact button
    connect(this,SIGNAL(triggerClear()),this,SLOT(onClearClicked()));
    connect(this->ui->buttonDelete,SIGNAL(clicked()),this,SLOT(onDeleteClicked()));

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

    // Disabling more info button since no selection has been made.
    this->ui->buttonInfo->setEnabled(false);

    // More information button connect
    connect(this->ui->buttonInfo,SIGNAL(clicked()),this,SLOT(onMoreInfoClicked()));



    this->currentAttribute=0;
}

/**
 * <p></p>
 * @brief Sets the current loaded contacts with a list of ContactID.
 * @param lst
 */
void FindContact::init(std::list<ContactID>* lst){
    this->loadedContacts = lst;
    updateResultView();
}

/**
 * Looping on all the contacts from loadedContacts. Adding to the QTableView a contact only if he meets all the requirements :<br>
 * - The keyword in the lineedit is contained within the criteria value from the combo box (first name, last name, ...) of this contact.<br>
 * - The date of creation of the contact is set between both dates selected by the user in the QCalendar.<br><br>
 * <b>This function is called in the constructor and when the slot onContactListUpdate() is triggered.</b>
 * Adds a hidden column named "id", storing the id of the ContactID.
 * @brief Fills the QTableView according to the search and sorting results.
 */
void FindContact::updateResultView(){
    this->model->setRowCount(0); // https://stackoverflow.com/a/15849800

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

    int count = 0;

    for (it = this->loadedContacts->begin(); it != this->loadedContacts->end(); ++it){
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
            count++;
        }
    }
    this->ui->labelCount->setText(" Total : "+QString::number(this->loadedContacts->size()) + " | Shown in view : "+QString::number(count));
}

/**
 * Slot triggered when the user uses the LineEdit, changes the dates, adds, updates or finally deletes a contact.
 * @brief Slot calling updateResultView() to update the QTableView.
 */
void FindContact::onContactListUpdate(){
    this->updateResultView();
}

/**
 * Sets the minimum date and the maximum date for the QCalendarWidget. The begin date can be picked between 01-01-1970 and 31-12-2500.
 * @brief Slot called when clicking on From: button
 */
void FindContact::pickDateBegin()
{
    qc->setMinimumDate( QDate::fromString("01-01-1970",QString("dd-MM-yyyy") ) );
    qc->setMaximumDate( QDate::fromString("31-12-2500",QString("dd-MM-yyyy") ) );
    currentQLE = this->ui->lineDate1;
    qc->show();
}

/**
 * Sets the minimum date to From: date, and max date to 31-12-2500. <br>
 * @brief Slot called when clicking on To: button
 */
void FindContact::pickDateEnd()
{
    currentQLE = this->ui->lineDate2;

    if(!this->ui->lineDate1->text().toStdString().empty())
        qc->setMinimumDate( QDate::fromString(this->ui->lineDate1->text(),QString("dd-MM-yyyy") ) );
    qc->show();
}

/**
 * <p></p>
 * @brief Slot ensuring the From: date is always inferior to To: date. Called whenever the To: date is changed.
 */
void FindContact::setDate()
{

    currentQLE->setText(qc->selectedDate().toString("dd-MM-yyyy"));

    if(QDate::fromString(this->ui->lineDate1->text(),QString("dd-MM-yyyy")) > QDate::fromString(this->ui->lineDate2->text(),QString("dd-MM-yyyy")))
        this->ui->lineDate2->setText(this->ui->lineDate1->text());

    updateResultView();
}

/**
 * Retrieves the index of the clicked row, and gets the value at the ID column... This is the ID of the clicked contact.
 * It is now possible to search in the ContactID list using the ID.
 * @brief Slot setting the CurrentContact attribute to the contact clicked in the QTableView.
 * @param index
 */
void FindContact::onResultViewClicked(const QModelIndex &index)
{
    QString cellText = index.data().toString();
    QAbstractItemModel *model = ui->resultView->model();
    int i = model->index(index.row(), 6).data().toString().toInt();
    std::list<ContactID>::iterator it;

    for (it = this->loadedContacts->begin(); it != this->loadedContacts->end(); ++it) {
        if(it->id == i){
            selectedContact = &(*it);
            this->ui->buttonInfo->setEnabled(true);
            break;
        }
    }

}

/**
 * <p></p>
 * @brief Slot called when clicking on Clear selection button. Points selectedContact attribute on nullptr, and clears the selection in the TableView.
 */
void FindContact::onClearClicked()
{
    this->ui->resultView->clearSelection();
    this->selectedContact = nullptr;
    this->ui->buttonInfo->setEnabled(false);
}

/**
 * <p></p>
 * @brief Opens an InfoContact form, passing the selectedContact attribute as a parameter when clicking on More Info button.
 */
void FindContact::onMoreInfoClicked()
{
    this->ic = new InfoContact(nullptr,this->selectedContact);
    connect(this->ic,SIGNAL(updateContact()),this,SLOT(onUpdateContact()));
    ic->setAttribute(Qt::WA_DeleteOnClose);
    ic->setWindowModality(Qt::ApplicationModal);
    ic->show();
}

/**
 * Calls ses the SQLInterface::deleteContact() method to delete the contact from the database.
 * Then, calls std::list<ContactID>::remove(ContactID) to remove the contact from the application.
 * Refreshes the view.
 * @brief Slot deleting selectedContact from the application when clicking on delete button.
 */
void FindContact::onDeleteClicked()
{
    this->sqli.deleteContact(*(this->selectedContact));
    this->loadedContacts->remove(*(this->selectedContact));
    emit triggerClear();
    this->updateResultView();
}

/**
 * First inserts all the contacts interactions in mp (the global MapInteractionTodo of the app).<br>
 * Insert operation overwrites the existing interactions, therefore there are no doubles.<br>
 * We consider an update to be a deletion followed by an insert.<br>
 * Then, we use the SQLInterface updateContact and addAllInteractions methods to update the database.
 * @brief Slot called when a contact has been updated in an InfoContact form. Updates the contact in the database and the application.
 */
void FindContact::onUpdateContact()
{
    // Mapping the new interactions according to their Todos
    std::list<Interaction *> lst = this->ic->currentContact->contact->getInteractions();
    std::list<Interaction *>::iterator itInter;
    for(itInter = lst.begin() ; itInter != lst.end() ; itInter++)
        this->mp->insert( *itInter );
    this->sqli.addAllInteractions(*(this->ic->currentContact),*(this->mp));
    this->sqli.updateContact(*(this->ic->currentContact));
    this->updateResultView();
}

/**
 * <p></p>
 * @brief Slot called when the combobox gets updated. Simply refreshes the QTableView.
 */
void FindContact::onComboBoxItemChanged(){
    this->currentAttribute = this->ui->findByComboBox->currentIndex();
    this->updateResultView();
}

/**
 * <p></p>
 * @brief Slot called when the lineEdit gets updated. Simply refreshes the QTableView.
 */
void FindContact::onInputChanged(){
    this->currentAttributeValue=this->ui->userInput->text().toStdString();
    std::transform(this->currentAttributeValue.begin(), this->currentAttributeValue.end(), this->currentAttributeValue.begin(), ::tolower); // lower input

    this->updateResultView();
}

/**
 * <p></p>
 * @brief Slot that gets called on window resize. Resizes the QTableFiew to fit the window.
 * @param event
 */
void FindContact::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    int size0 = this->ui->resultView->width()*0.15;
    int size1 = this->ui->resultView->width()*0.25;
    this->ui->resultView->setColumnWidth(0, size0);
    this->ui->resultView->setColumnWidth(1, size0);
    this->ui->resultView->setColumnWidth(2, size0);
    this->ui->resultView->setColumnWidth(3, size1);
    this->ui->resultView->setColumnWidth(4, size0);

    // size2 = size1 + int to compensate rounded divisions and avoid scrollbar
    int size2 = this->ui->resultView->width()-size0*4-size1;
    this->ui->resultView->setColumnWidth(5, size2);
}


/**
 * <p></p>
 * @brief Basic destructor.
 */
FindContact::~FindContact(){
    delete this->ui;
    delete this->model;
}
