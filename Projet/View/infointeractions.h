#ifndef INFOINTERACTIONS_H
#define INFOINTERACTIONS_H

#include <QWidget>
#include <QTableWidget>
#include <Model/mapinteractiontodo.h>
#include "../Model/structid.h"

namespace Ui {
class InfoInteractions;
}

class InfoInteractions : public QWidget
{
    Q_OBJECT

public:
    explicit InfoInteractions(QWidget *parent = nullptr, std::list<ContactID> * = nullptr, MapInteractionTodo * = nullptr);
    ~InfoInteractions();

    std::list<ContactID> * loadedContacts;
    MapInteractionTodo * mapInterationTodo;

    void fillInteractions();


public slots :
    void fillTodos();


private:
    Ui::InfoInteractions *ui;
    QTableWidget * viewInteractions;
    QTableWidget * viewTodos;
};

#endif // INFOINTERACTIONS_H
