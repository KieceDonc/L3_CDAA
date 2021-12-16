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

/**
 * @brief Mainwindow's main widget : Shows the list of contact attributes as a spreadsheet, using QTableViews. Allow sorting, searching, and selection to perform different actions.
 */
class FindContact : public QWidget{
    Q_OBJECT

    public:
        explicit FindContact(QWidget *parent = nullptr);
        ~FindContact();
        void updateResultView();
        void init(std::list<ContactID>* lst);

        Ui::FindContact *ui;
        QStandardItemModel* model;
        QList<QStandardItem*> rowData;
        std::string currentAttributeValue;
        QLineEdit * currentQLE;
        QCalendarWidget * qc;
        InfoContact * ic;
        SQLInterface sqli;
        MapInteractionTodo * mp;
        ContactID * selectedContact;
        std::list<ContactID>* loadedContacts;

        int currentAttribute;

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

    signals:
        void triggerClear();


    protected:
        void resizeEvent(QResizeEvent *event);


};

#endif // FINDCONTACT_H
