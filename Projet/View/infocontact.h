#ifndef INFOCONTACT_H
#define INFOCONTACT_H

#include <QWidget>
#include <Model/contact.h>

namespace Ui {
class InfoContact;
}

class InfoContact : public QWidget
{
    Q_OBJECT

public:
    explicit InfoContact(QWidget *parent = nullptr, Contact * c = nullptr);
    ~InfoContact();

private:
    Ui::InfoContact *ui;
    Contact * currentContact;
};

#endif // INFOCONTACT_H
