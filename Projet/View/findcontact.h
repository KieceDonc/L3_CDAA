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
        void updateResultView();
        void init(std::list<ContactID>* lst);

        std::list<ContactID>* loadedContacts;
        MapInteractionTodo * mp;


    public slots:
        void onContactListUpdate();
        void onUpdateContact();

        void pickDateBegin();
        void pickDateEnd();
        void setDate();

        void onComboBoxItemChanged();
        void onInputChanged();
        void onClearClicked();
        void onMoreInfoClicked();
        void onDeleteClicked();
        void onResultViewClicked(const QModelIndex &index);

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

    signals:
        void triggerClear();


    protected:
        void resizeEvent(QResizeEvent *event);


};

#endif // FINDCONTACT_H
