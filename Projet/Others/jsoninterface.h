#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"

#include "../Model/contact.h"
#include "../Model/contactidinterface.h"
#include "../Model/interaction.h"
#include "../Model/interactiontodo.h"
#include "../Model/todo.h"

class JSONInterface{
public:
    JSONInterface();
    void addContact(Contact& contact);
    QJsonValue convertStringToQJsonValue(std::string s);

private:
    QJsonDocument  json;
    QJsonArray contactList;
};

#endif // JSONINTERFACE_H
