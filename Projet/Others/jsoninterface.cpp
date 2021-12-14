#include "jsoninterface.h"

JSONInterface::JSONInterface(){

}

void JSONInterface::addContact(Contact& contact){
    QJsonObject contactObject;
    contactObject.insert("Prénom",convertStringToQJsonValue(contact.getFirstName()));
    contactObject.insert("Nom",convertStringToQJsonValue(contact.getLastName()));
    contactObject.insert("Entreprise",convertStringToQJsonValue(contact.getEnterprise()));
    contactObject.insert("Mail",convertStringToQJsonValue(contact.getMail()));
    contactObject.insert("Téléphone",convertStringToQJsonValue(contact.getPhone()));
    //contactObject.insert("Photo",convertStringToQJsonValue(contact.()));
    contactObject.insert("Date de création",convertStringToQJsonValue(contact.getDateOfCreation().toString()));
    contactObject.insert("Intéraction",convertStringToQJsonValue(contact.getFirstName()));

    QJsonArray interactionListJSON;
    std::list<Interaction*> interactionList = contact.getInteractions();
    for (int x=0 ;x<interactionList.size();x++){
        QJsonObject currentInteractionJSON;
        std::list<Interaction*>::iterator it = interactionList.begin();
        Interaction * currentInteraction = std::advance(it, x);
        interactionListJSON.push_back(currentInteractionJSON);
    }
    contactObject.insert("Intéractions",interactionList);

    Photo photo;
    std::list<Interaction *> interactions;
    this->contactList.push_back(contactObject);
}

/*void JSONInterface::addContactinteraction( contactid , interactionid ){

}
void JSONInterface::addInteraction( interactionid , interactioncontent , interactiondate ){

}

void JSONInterface::addInteractiontodo( interactionid , todoid ){

}

void JSONInterface::addTodo( todoid , todocontent , tododate ){

}

void JSONInterface::export(){

}*/

QJsonValue JSONInterface::convertStringToQJsonValue(std::string s){
   return QString::fromStdString(s);
}
