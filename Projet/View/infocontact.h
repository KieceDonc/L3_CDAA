#ifndef INFOCONTACT_H
#define INFOCONTACT_H

#include <QWidget>
#include <Model/contact.h>
#include <Model/structID.h>

namespace Ui {
class InfoContact;
}

class InfoContact : public QWidget
{
    Q_OBJECT

public:
    explicit InfoContact(QWidget *parent = nullptr, ContactID * c = nullptr);
    ~InfoContact();

private:
    Ui::InfoContact *ui;
    ContactID * currentContact;
};

#endif // INFOCONTACT_H
