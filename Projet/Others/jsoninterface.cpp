#include "jsoninterface.h"

/**
 * <p></p>
 * @brief The constructor simply initializes its attributes which are different arrays of types.
 */
JSONInterface::JSONInterface(){

}

/**
 * <p></p>
 * @brief Calls addContact on each contactID for the list of ContactID passed in parameter.
 * @param contactList a list of ContactID
 */
void JSONInterface::addContact(std::list<ContactID>* contactList){
    for (auto it = contactList->begin(); it != contactList->end(); ++it){
        this->addContact(*(it));
    }
}

/**
 * Converts all the contact attributes into QJsonValues. <br>
 * For each interactions of this contact, pushes the content and the date into a QJsonArray.
 * @brief Converts a contact and its interactions as a QJsonObject and pushes it into the QJsonArray.
 * @param contactID
 */
void JSONInterface::addContact(ContactID& contactID){
    QJsonObject contactObject;
    Contact contact = *(contactID.contact);

    contactObject.insert("ID",contactID.id);
    contactObject.insert("First Name",convertStringToQJsonValue(contact.getFirstName()));
    contactObject.insert("Last Name",convertStringToQJsonValue(contact.getLastName()));
    contactObject.insert("Entreprise",convertStringToQJsonValue(contact.getEnterprise()));
    contactObject.insert("Mail",convertStringToQJsonValue(contact.getMail()));
    contactObject.insert("Phone",convertStringToQJsonValue(contact.getPhone()));
    contactObject.insert("Photo",convertStringToQJsonValue(contact.getPhoto()));
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

/**
 * <p></p>
 * @brief Writes the current JSON into a file. The path and the name are passed in parameters.
 * @param std::string : path
 * @param std::string : name
 */
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

/**
 * <p></p>
 * @brief Returns a QJsonValue from the string passed in parameter
 * @param std::string
 * @return QJsonValue
 */
QJsonValue JSONInterface::convertStringToQJsonValue(std::string s){
   return QString::fromStdString(s);
}
