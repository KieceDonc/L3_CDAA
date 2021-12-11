#ifndef FINDCONTACT_H
#define FINDCONTACT_H

#include <QDebug>
#include <QWidget>
#include <QStandardItem>
#include <QCalendarWidget>
#include <QLineEdit>

#include "../Model/structID.h"
#include "../Others/sqlinterface.h"

namespace Ui {
    class FindContact;
}

class FindContact : public QWidget{
    Q_OBJECT

    public:
        explicit FindContact(QWidget *parent = nullptr);
        ~FindContact();


    public slots:
        void onComboBoxItemChanged();
        void onInputChanged();
        void onContactListUpdate();
        void pickDateBegin();
        void pickDateEnd();
        void setDate();


    private:
        Ui::FindContact *ui;
        QStandardItemModel* model;
        QList<QStandardItem*> rowData;

        QCalendarWidget * qc;
        QLineEdit * currentQLE;

        SQLInterface sqli;

        std::list<ContactID> loadedContacts;

        int currentAttribute;
        std::string currentAttributeValue;



        void updateResultView();
        void loadListOfContact();
        void deleteContact();


};

#endif // FINDCONTACT_H
