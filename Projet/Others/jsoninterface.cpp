#include "jsoninterface.h"

#include "QDebug"

JSONInterface::JSONInterface(){
    //this->writeInFile("/mnt/3822CDE622CDA8E8/Coding_workplace/L3_CDAA/Projet/JSONExport","test");
}

void JSONInterface::addContact(std::list<ContactID>* contactList){
    for (auto it = contactList->begin(); it != contactList->end(); ++it){
        this->addContact(*(it));
    }
}

void JSONInterface::addContact(ContactID& contactID){
    QJsonObject contactObject;
    Contact contact = *(contactID.contact);

    contactObject.insert("ID",contactID.id);
    contactObject.insert("Prénom",convertStringToQJsonValue(contact.getFirstName()));
    contactObject.insert("Nom",convertStringToQJsonValue(contact.getLastName()));
    contactObject.insert("Entreprise",convertStringToQJsonValue(contact.getEnterprise()));
    contactObject.insert("Mail",convertStringToQJsonValue(contact.getMail()));
    contactObject.insert("Téléphone",convertStringToQJsonValue(contact.getPhone()));
    //contactObject.insert("Photo",convertStringToQJsonValue(contact.()));
    contactObject.insert("Date de création",convertStringToQJsonValue(contact.getDateOfCreation().toString()));

    QJsonArray interactionListJSON;
    std::list<Interaction*> interactionList = contact.getInteractions();
    for (auto it = interactionList.begin(); it != interactionList.end(); ++it){
        QJsonObject currentInteractionJSON;
        currentInteractionJSON.insert("Contenu",convertStringToQJsonValue((*it)->getContent()));
        currentInteractionJSON.insert("Date",convertStringToQJsonValue((*it)->getDate().toString()));
        interactionListJSON.push_back(currentInteractionJSON);
    }
    contactObject.insert("Intéractions",interactionListJSON);

    this->contactListJSON.push_back(contactObject);
}

void JSONInterface::addInteractionTodos(InteractionTodos& interactions){
    for (auto it = interactions.getItList()->begin(); it != interactions.getItList()->end(); ++it){
        this->addInteractionTodo(*(it));
    }
}

void JSONInterface::addInteractionTodo(InteractionTodo& interaction){
    QJsonObject interactionTodoJSON;

    QJsonObject currentInteractionJSON;
    QJsonObject currentTodoJSON;
    currentInteractionJSON.insert("Contenu",convertStringToQJsonValue(interaction.getI()->getContent()));
    currentInteractionJSON.insert("Date",convertStringToQJsonValue(interaction.getI()->getDate().toString()));
    currentInteractionJSON.insert("Contenu",convertStringToQJsonValue(interaction.getT()->getContent()));
    currentInteractionJSON.insert("Date",convertStringToQJsonValue(interaction.getT()->getDate().toString()));

    interactionTodoJSON.insert("Todo",currentTodoJSON);
    interactionTodoJSON.insert("Intéraction",currentInteractionJSON);
    this->interactionTodoListJSON.push_back(interactionTodoJSON);
}

void JSONInterface::writeInFile(const QString& path,const QString& name){
    QJsonObject root;
    root.insert("Contact",this->contactListJSON);
    root.insert("IntéractionsTodo",this->interactionTodoListJSON);
    this->doc.setObject(root);

    QFile file(path+"/"+name+".json");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "File open error";
        } else {
            qDebug() <<"File open!";
        }

    file.resize(0);
    file.write(this->doc.toJson());
    file.close();
}

QJsonValue JSONInterface::convertStringToQJsonValue(std::string s){
   return QString::fromStdString(s);
}
