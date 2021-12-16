#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <map>
#include <QCalendarWidget>

#include <Model/todo.h>

#include "customform.h"
#include "./Model/structid.h"
#include "./Others/sqlinterface.h"
#include "findcontact.h"
#include "infointeractions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow allows two actions : Chosing an action in the action bar on the top, and displaying its central widget : A FindContact widget.
 * Contains most model objects, and shares pointers on them to other widgets.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CustomForm* contactForm;
    CustomForm* interactionForm;
    CustomForm* currentForm;
    FindContact* findcontact;

    std::list<ContactID> loadedContacts;
    MapInteractionTodo mapInteractionTodo;
    SQLInterface sqli;
    Ui::MainWindow *ui;

public slots:
    void onContactFormComplete();
    void onQActionContactClicked();
    void onActionExportJsonClicked();
    void onDisplayInteractionClicked();
    void loadContacts();
    void makeJson(const QString & path);

signals:
    void onContactListUpdate();
};

#endif // MAINWINDOW_H
