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
    void fillTodos();


public slots :
    void switchViews();
    void sortViews();

private:
    Ui::InfoInteractions *ui;
    QTableWidget * viewInteractions;
    QTableWidget * viewTodos;

signals:
    void triggerSortViews();

protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // INFOINTERACTIONS_H
