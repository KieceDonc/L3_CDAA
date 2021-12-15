#ifndef JSONINTERFACE_H
#define JSONINTERFACE_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

#include "../Model/structid.h"
#include "../Model/contact.h"
#include "../Model/todo.h"

class JSONInterface{

    public:
        JSONInterface();
        void addContact(std::list<ContactID>* contactList);
        void addContact(ContactID& contact);
        void writeInFile(const QString& path,const QString& name);
        QJsonValue convertStringToQJsonValue(std::string s);

    private:
        QJsonDocument doc;
        QJsonArray contactListJSON;
};

#endif // JSONINTERFACE_H
