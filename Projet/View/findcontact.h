#ifndef FINDCONTACT_H
#define FINDCONTACT_H

#include <QDebug>
#include <QWidget>
#include <QStandardItem>
#include <QCalendarWidget>
#include <QLineEdit>

#include "../Model/structID.h"
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
        std::list<ContactID> loadedContacts;
        int currentAttribute;
        std::string currentAttributeValue;
        Contact * selectedContact;

        void loadListOfContact();
        void deleteContact();
        void updateResultView();


    protected:
        void resizeEvent(QResizeEvent *event);


};

#endif // FINDCONTACT_H
