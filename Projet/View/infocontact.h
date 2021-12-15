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

class InfoContact : public QWidget
{
    Q_OBJECT

public:
    explicit InfoContact(QWidget *parent = nullptr, ContactID * c = nullptr);
    ~InfoContact();

    ContactID * currentContact;

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

private:
    Ui::InfoContact *ui;
    QSignalMapper *signalMapper;
};

#endif // INFOCONTACT_H
