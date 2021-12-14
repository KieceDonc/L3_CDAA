#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>


#include "../Model/structid.h"
#include "../Model/contact.h"
#include "../Model/interactiontodo.h"
#include "../Model/interactiontodos.h"
#include "../Model/todo.h"

class JSONInterface{

    public:
        JSONInterface();
        void addContact(std::list<ContactID>* contactList);
        void addContact(ContactID& contact);
        void addInteractionTodos(InteractionTodos& interactions);
        void addInteractionTodo(InteractionTodo& interaction);
        void writeInFile(const QString& path,const QString& name);
        QJsonValue convertStringToQJsonValue(std::string s);

    private:
        QJsonDocument doc;
        QJsonArray contactListJSON;
        QJsonArray interactionTodoListJSON;
};

#endif // JSONINTERFACE_H
