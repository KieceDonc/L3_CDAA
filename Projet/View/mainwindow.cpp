#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findcontact.h"
#include "jsonform.h"

#include <Others/jsoninterface.h>

/**
  * @class MainWindow
  * The MainWindow doesn't display much stuff. It contains an action bar at the top, allowing 3 different actions. The central layout is a FindContact object.
  * Without it the window looks like this :
  * <img src="../assets/MainWindow.png">
  * Although a setCentralLayout saves the day because it looks quite empty for now.
  */

/**
 * @brief Initializes the mainwindow. Hosts all of the important variables.
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Creating the list of contacts, and an object mapping interaction to todos.
    this->loadedContacts = std::list<ContactID>();
    this->mapInteractionTodo = MapInteractionTodo();

    // Initializing the contacts list with sql interface
    this->loadContacts();

    // Connecting actions
    connect(this->ui->actionContact,SIGNAL(triggered()),this,SLOT(onQActionContactClicked()));
    connect(this->ui->actionDisplayInteractions,SIGNAL(triggered()),this,SLOT(onDisplayInteractionClicked()));
    connect(this->ui->actionExport_JSON,SIGNAL(triggered()),this,SLOT(onActionExportJsonClicked()));

    findcontact = new FindContact();
    this->findcontact->mp = &(this->mapInteractionTodo);
    this->ui->middleLayout->addWidget(findcontact);
    findcontact->init(&this->loadedContacts);
    connect(this,SIGNAL(onContactListUpdate()),this->findcontact,SLOT(onContactListUpdate()));
}

/**
 * This slot is called when the signal onDataReady() from CustomForm is emited.<br>
 * It creates a contact from the data in a try catch block. The exception caught can come from the Contact's constructor.
 * If to exceptions are caught, then the contact is inserted into the database and the global ContactID list.
 * @brief Slot constructing a contact after a CustomForm completion.
 */
void MainWindow::onContactFormComplete(){
    std::map<QString,QString> data = this->currentForm->getData();

    QString contactFirstName = data.at("First Name");
    QString contactLastName = data.at("Last Name");
    QString contactEntreprise = data.at("Entreprise");
    QString contactEmail = data.at("Email");
    QString contactPhone = data.at("Phone");
    QString contactPhoto = data.at("Photo");
    try{
        Contact c = Contact(contactFirstName.toStdString(),contactLastName.toStdString(),contactEntreprise.toStdString(),contactEmail.toStdString(),contactPhone.toStdString(),contactPhoto.toStdString(),Date());
        this->sqli.insertContact(c,&(this->loadedContacts));
        this->loadedContacts = std::list<ContactID>();
        this->loadContacts();
    }catch(...){
            qDebug()<< "Impossible de créer le contact.";
        }
    emit onContactListUpdate();
}


/**
 * Opens a CustomForm with the parameters required to make a contact. Connects the signal OnDataReady() that is triggered when pressing "Ok" in this form - to the slot onContactFormComplete().
 * @brief Slot triggered when clicking on the "Add contact" action in the actionbar.
 */
void MainWindow::onQActionContactClicked(){
    if(!this->contactForm)
        delete this->contactForm;
    this->contactForm = new CustomForm();
    contactForm->setAttribute(Qt::WA_DeleteOnClose);
    contactForm->setWindowModality(Qt::ApplicationModal);
    connect(this->contactForm,SIGNAL(onDataReady()),this,SLOT(onContactFormComplete()));
    this->contactForm->init({"First Name","Last Name","Entreprise","Email","Phone","Photo"});

    //this->setCentralWidget(this->contactForm);
    this->currentForm = this->contactForm;
}

/**
 * Opens a JsonForm and shows it.
 * @brief Slot triggered when clicking on the "Export JSON" action in the actionbar.
 */
void MainWindow::onActionExportJsonClicked(){
    JsonForm * jsf = new JsonForm();
    connect(jsf,SIGNAL(makeJson(const QString &)),this,SLOT(makeJson(const QString &)));
    jsf->show();
}

/**
 * Opens an InfoInteractions and shows it.
 * @brief Slot triggered when clicking on the "Display Interactions" action in the actionbar.
 */
void MainWindow::onDisplayInteractionClicked(){
    InfoInteractions * ii = new InfoInteractions(nullptr,&(this->loadedContacts),&(this->mapInteractionTodo));
    ii->setAttribute(Qt::WA_DeleteOnClose);
    ii->setWindowModality(Qt::ApplicationModal);
    ii->show();
}

/**
 * Uses the SQLInterface::getAllContacts(std::list<ContactID>,MapInteractionTodo) method.
 * @brief Calls the SQLInterface() to fill the contact list with the Database contacts, and map the Interactions to their respective Todos.
 */
void MainWindow::loadContacts(){
    this->sqli.getAllContacts(this->loadedContacts, this->mapInteractionTodo);
    emit onContactListUpdate();
}

/**
 * @brief Basic destructor.
 */
MainWindow::~MainWindow(){
    delete ui;
    if(!this->contactForm)
        delete this->contactForm;
    if(!this->interactionForm)
        delete this->interactionForm;

}

/**
 * Slot called when the "ok" button from JsonForm is clicked().
 * @brief Slot generating a JSON file at the path indicated in a JsonForm.
 * @param path
 */
void MainWindow::makeJson(const QString & path)
{
    JSONInterface jsi = JSONInterface();
    jsi.addContact(&(this->loadedContacts));
    jsi.writeInFile(path,"ContactManagement");
}
