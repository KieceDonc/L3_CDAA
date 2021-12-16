#ifndef INFOCONTACT_H
#define INFOCONTACT_H

#include <QSignalMapper>
#include <QWidget>
#include <Model/contact.h>
#include <Model/structid.h>
#include <Others/sqlinterface.h>

namespace Ui {
class InfoContact;
}

/**
 * @brief Widget that displays all of a contact's attributes, including its picture. Dynamically allows Interactions edition, creation and deletion.
 */
class InfoContact : public QWidget
{
    Q_OBJECT

public:
    explicit InfoContact(QWidget *parent = nullptr, ContactID * c = nullptr);
    ~InfoContact();

    ContactID * currentContact;
    Ui::InfoContact *ui;
    QSignalMapper *signalMapper;

public slots :
    void displayInteractions();
    void onApplyClicked();
    void onDeleteButtonClicked(int);
    void onAddInteractionClicked();
    void showPhoto();

signals :
    void clicked(int);
    void updateContact();
    void triggerShowPhoto();

};

#endif // INFOCONTACT_H
