#ifndef FINDCONTACT_H
#define FINDCONTACT_H

#include <QDebug>
#include <QWidget>
#include <QStandardItem>
#include <QCalendarWidget>
#include <QLineEdit>

#include "../Model/structid.h"
#include "../Others/sqlinterface.h"
#include "../View/infocontact.h"

namespace Ui {
    class FindContact;
}

class FindContact : public QWidget{
    Q_OBJECT

    public:
        explicit FindContact(QWidget *parent = nullptr);
        ~FindContact();

        void init(std::list<ContactID>* lst);
        std::list<ContactID>* loadedContacts;


    public slots:
        void onComboBoxItemChanged();
        void onInputChanged();
        void onContactListUpdate();
        void pickDateBegin();
        void pickDateEnd();
        void setDate();
        void onResultViewClicked(const QModelIndex &index);
        void onClearClicked();
        void onMoreInfoClicked();




    private:
        Ui::FindContact *ui;
        QStandardItemModel* model;
        QList<QStandardItem*> rowData;
        QCalendarWidget * qc;
        InfoContact * ic;
        QLineEdit * currentQLE;
        SQLInterface sqli;
        int currentAttribute;
        std::string currentAttributeValue;
        ContactID * selectedContact;

        void updateResultView();


    protected:
        void resizeEvent(QResizeEvent *event);


};

#endif // FINDCONTACT_H
