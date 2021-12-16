#ifndef INFOINTERACTIONS_H
#define INFOINTERACTIONS_H

#include <QWidget>
#include <QTableWidget>
#include <Model/mapinteractiontodo.h>
#include "../Model/structid.h"

namespace Ui {
class InfoInteractions;
}

/**
 * @brief Displays ALL the interactions and todos from the database in QTableWidgets (Better version of QTableViews). Allows sorting and searching.
 */
class InfoInteractions : public QWidget
{
    Q_OBJECT

public:
    explicit InfoInteractions(QWidget *parent = nullptr, std::list<ContactID> * = nullptr, MapInteractionTodo * = nullptr);
    ~InfoInteractions();

    Ui::InfoInteractions *ui;
    std::list<ContactID> * loadedContacts;
    MapInteractionTodo * mapInterationTodo;
    QTableWidget * viewInteractions;
    QTableWidget * viewTodos;

    void fillInteractions();
    void fillTodos();

public slots :
    void switchViews();
    void sortViews();

signals:
    void triggerSortViews();

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // INFOINTERACTIONS_H
