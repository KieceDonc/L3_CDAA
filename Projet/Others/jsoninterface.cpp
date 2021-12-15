#include "jsoninterface.h"


JSONInterface::JSONInterface(){
    //this->writeInFile("/home/stinky/Bureau","test");

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
    contactObject.insert("First Name",convertStringToQJsonValue(contact.getFirstName()));
    contactObject.insert("Last Name",convertStringToQJsonValue(contact.getLastName()));
    contactObject.insert("Entreprise",convertStringToQJsonValue(contact.getEnterprise()));
    contactObject.insert("Mail",convertStringToQJsonValue(contact.getMail()));
    contactObject.insert("Phone",convertStringToQJsonValue(contact.getPhone()));
    //contactObject.insert("Photo",convertStringToQJsonValue(contact.()));
    contactObject.insert("Date",convertStringToQJsonValue(contact.getDateOfCreation().toString()));

    QJsonArray interactionListJSON;
    std::list<Interaction*> interactionList = contact.getInteractions();
    for (auto it = interactionList.begin(); it != interactionList.end(); ++it){
        QJsonObject currentInteractionJSON;
        currentInteractionJSON.insert("Content",convertStringToQJsonValue((*it)->getContent()));
        currentInteractionJSON.insert("Date",convertStringToQJsonValue((*it)->getDate().toString()));
        interactionListJSON.push_back(currentInteractionJSON);
    }
    contactObject.insert("Interactions",interactionListJSON);

    this->contactListJSON.push_back(contactObject);
}

void JSONInterface::writeInFile(const QString& path,const QString& name){
    QJsonObject root;
    root.insert("Contact",this->contactListJSON);
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
