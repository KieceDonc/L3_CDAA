#include "infocontact.h"
#include "ui_infocontact.h"
#include <QDateEdit>
#include <QDebug>
#include <QDir>
#include <QGraphicsScene>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGraphicsScene>

/**
 * @class InfoContact
 * Window that allows the user to edit most informations but the picture about any contact.<br>
 * The user can change each attributes using lineEdits.<br>
 * The list of interactions is shown, each of them consists of a layout containing : a button to delete it, a QDateEdit to change its date, and a QPlainTextEdit to change the interaction content.<br>
 * Clicking on "Add interaction" dynamically generates a layout for a new interaction.<br>
 * Clicking on save updates the application and the database with new data.<br>
 * Clicking on the button to delete an interaction doesn't exactly delete it. As long as the window has not been closed, the user can retrieving by clicking the button again, as seen on this screenshot :<br>
 * <img src="../assets/InfoContact.png">
 */

/**
 * Emits displayInteractions() signal to fill de interactions.
 * @brief Constructor taking a contact pointer as parameter, and fills all the fields with the contact values.
 * @param ContactID *
 */
InfoContact::InfoContact(QWidget *parent, ContactID * c) :
    QWidget(parent),
    ui(new Ui::InfoContact)
{
    ui->setupUi(this);
    this->currentContact = c;
    ui->lineFirstName->setText(QString::fromStdString(c->contact->getFirstName()));
    ui->lineLastName->setText(QString::fromStdString(c->contact->getLastName()));
    ui->lineEntreprise->setText(QString::fromStdString(c->contact->getEnterprise()));
    ui->lineMail->setText(QString::fromStdString(c->contact->getMail()));
    ui->linePhone->setText(QString::fromStdString(c->contact->getPhone()));
    ui->label_i->setFixedHeight((40));
    emit(displayInteractions());

    connect(this->ui->buttonSave,SIGNAL(clicked()),this,SLOT(onApplyClicked()));
    connect(this,SIGNAL(clicked(int)),this,SLOT(onDeleteButtonClicked(int)));
    connect(this->ui->buttonAddInteraction,SIGNAL(clicked()),this,SLOT(onAddInteractionClicked()));
    connect(this,SIGNAL(triggerShowPhoto()),this,SLOT(showPhoto()));
    emit(triggerShowPhoto());

    //this->ui->interactionLayout->
}

/**
 * For each interaction, creates a layout containing widgets allowing editing of interactions : A delete button, a QDateEdit and a QPlainTextEdit.<br>
 * A QSignalMapper maps the signal clicked() of each dynamically generated buttons to an int. Therefore on click, we know which button has been clicked.<br>
 * @brief Displays the lists of interactions at the bottom of the window.
 */
void InfoContact::displayInteractions(){
    std::list<Interaction *> lst = this->currentContact->contact->getInteractions();
    int iButton = 0;
    signalMapper = new QSignalMapper(this);
    connect(this->signalMapper, SIGNAL(mapped(int)), this, SIGNAL(clicked(int)));

    //emit(emptyInteractionsLayout());

    if(!lst.empty()){

        std::list<Interaction *>::iterator it;
        for(it = lst.begin() ; it != lst.end() ; it++){

            QHBoxLayout * qhb = new QHBoxLayout();
            QPushButton * b = new QPushButton();
            QDateEdit * ldate = new QDateEdit();
            QPlainTextEdit * lcont = new QPlainTextEdit();
            std::list<QHBoxLayout> lstInteractionLayout;

            // Delete button properties
            b->setText("✕"); // "✕"
            b->setFixedWidth(20);
            b->setFixedHeight(20);

            // Date edit properties
            ldate->setDisplayFormat("dd-MM-yyyy");
            ldate->setDate(QDate::fromString(QString::fromStdString( (*it)->getDate().toString() ),"dd-MM-yyyy"));

            // Todo content textedit properties
            lcont->appendPlainText( QString::fromStdString((*it)->getContent()));
            lcont->setMaximumHeight(50);
            qhb->addWidget(b);
            qhb->addWidget(ldate);
            qhb->addWidget(lcont);

            signalMapper->setMapping(b, iButton);
            connect(b, SIGNAL(clicked()), signalMapper, SLOT(map()));

            this->ui->interactionLayout->addLayout(qhb);
            iButton++;
        }
    }
}

/**
 * Sets the currentContact values to the field values.<br>
 * Deletes all of the currentContact interactions, and replaces them with the new ones. ( Deleting + Adding = Update).
 * Emits updatContact() to also update the Database.
 * @brief Slot called when the Save button has been clicked().
 */
void InfoContact::onApplyClicked()
{
    this->currentContact->contact->setFirstName(this->ui->lineFirstName->text().toStdString());
    this->currentContact->contact->setLastName(this->ui->lineLastName->text().toStdString());
    this->currentContact->contact->setEnterprise(this->ui->lineEntreprise->text().toStdString());
    this->currentContact->contact->setMail(this->ui->lineMail->text().toStdString());
    this->currentContact->contact->setPhone(this->ui->linePhone->text().toStdString());

    this->currentContact->contact->setInteractions(std::list<Interaction *>());

    for(int index = 0 ; index < this->ui->interactionLayout->count() ; index++){
        QHBoxLayout * qhb = dynamic_cast<QHBoxLayout *>(this->ui->interactionLayout->itemAt(index));
        QDateEdit * d = dynamic_cast<QDateEdit *>(qhb->itemAt(1)->widget());
        QPlainTextEdit * t = dynamic_cast<QPlainTextEdit *>(qhb->itemAt(2)->widget());
        if(d->isEnabled())
            this->currentContact->contact->addInteraction(new Interaction(d->date().toString("dd-MM-yyyy").toStdString(),t->toPlainText().toStdString()));
    }

    emit updateContact();
}

/**
 * Displays the interaction as deleted : As in, the delete button icon '✕'  turns into '↺' showing the user he can still retrieve it.<br>
 * The QLineEdit and QPlainTextEdit are disabled.<br>
 * If clicked again, the interaction goes back to normal.
 * @brief Thanks to the SignalMapper, this slot can take an int as parameter, telling it which delete button has been clicked.
 * @param
 */
void InfoContact::onDeleteButtonClicked(int i)
{

    //this->currentContact->contact->removeInteraction(i);
    //emit(displayInteractions());
    QHBoxLayout * qhb = dynamic_cast<QHBoxLayout *>(this->ui->interactionLayout->itemAt(i));
    QPushButton * b = dynamic_cast<QPushButton *>(qhb->itemAt(0)->widget());
    QDateEdit * d = dynamic_cast<QDateEdit *>(qhb->itemAt(1)->widget());
    QPlainTextEdit * t = dynamic_cast<QPlainTextEdit *>(qhb->itemAt(2)->widget());

    if(d->isEnabled()){
        d->setEnabled(false);
        t->setEnabled(false);
        b->setText("↺");
    }else{
        d->setEnabled(true);
        t->setEnabled(true);
        b->setText("✕");
    }
}

/**
 * <p></p>
 * @brief Slots called when Add Interaction button has been clicked. Adds a new interaction to currentContact and refreshes the view.
 */
void InfoContact::onAddInteractionClicked()
{
    QHBoxLayout * qhb = new QHBoxLayout();
    QPushButton * b = new QPushButton();
    QDateEdit * ldate = new QDateEdit();
    QPlainTextEdit * lcont = new QPlainTextEdit();
    std::list<QHBoxLayout> lstInteractionLayout;

    // Delete button properties
    b->setText("✕");
    b->setFixedWidth(20);
    b->setFixedHeight(20);

    // Date edit properties
    ldate->setDisplayFormat("dd-MM-yyyy");
    ldate->setDate(QDate::fromString(QString::fromStdString(Date().toString()),"dd-MM-yyyy"));

    // Todo content textedit properties
    lcont->appendPlainText("New interaction");
    lcont->setMaximumHeight(50);
    qhb->addWidget(b);
    qhb->addWidget(ldate);
    qhb->addWidget(lcont);

    signalMapper->setMapping(b, this->ui->interactionLayout->count());
    connect(b, SIGNAL(clicked()), signalMapper, SLOT(map()));

    this->ui->interactionLayout->addLayout(qhb);

}

/**
 * <p></p>
 * @brief Shows the photo of the contact from its path in a QGraphicsView. Slot called on interface generation, and resize event.
 */
void InfoContact::showPhoto()
{
    QString path = QString::fromStdString(this->currentContact->contact->getPhoto());
    QImage photo = QImage(path);
           if(!photo.isNull())
           {
               QImage photoScaled;
               if(photo.width() > photo.height()){
                   photoScaled = photo.scaledToWidth(300);
               }else{
                   photoScaled = photo.scaledToHeight(300);
               }
               QGraphicsScene* scene = new QGraphicsScene(this);
               scene->addPixmap(QPixmap::fromImage(photoScaled));
               delete ui->viewPhoto->scene();
               ui->viewPhoto->setScene(scene);
               ui->viewPhoto->setMinimumSize(photoScaled.width()*1.2,photoScaled.height()*1.2);
           }
}

/**
 * <p></p>
 * @brief Generic destructor.
 */
InfoContact::~InfoContact()
{
    delete ui;
}
