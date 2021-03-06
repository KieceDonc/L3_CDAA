#include "../headers/Contact.h"

/**
 * @class Contact
 * A contact represents an entity akin to a person, a group of persons, a service, a company...<br>
 * It is the main element of the class - Or at least the one that will be iterated onto the most along Interactions.<br>
 * A contact stores all of its basic informations (names, mail, etc...), a list of interactions.<br>
 */

/**
 * @brief Constructs a new Contact object from all its parameters. Because the Date() constructor allows it, it sets the creation date of the contact to the current date.
 * 
 * @param logs Contains all actions / logs applied on this contact
 * @param firstName 
 * @param lastName 
 * @param entreprise 
 * @param mail 
 * @param phone 
 * @param dateOfCreation 
 * @param photo 
 * @param interactions The interaction list of the contact.
 */
Contact::Contact(Logs * logs, const std::string& firstName, const std::string& lastName, const std::string& enterprise, const std::string& mail, const std::string& phone, const Photo& photo){
  this->inConstructor = true;
  this->logs = logs;
  this->setFirstName(firstName);
  this->setLastName(lastName);
  this->setEnterprise(enterprise);
  this->setMail(mail);
  this->setPhone(phone);
  this->setDateOfCreation();
  this->setPhoto(photo);
  this->interactions = std::list<Interaction *>();

  logs->add(Log(this,Log::ACTION_CREATION_CONTACT));
  this->inConstructor = false;
}

/**
 * @brief Sets the firstname of a contact. Must have at contain one character.
 * 
 * @throw invalid_argument firstname length must be higher than 0 
 * @param lastName
 */
void Contact::setFirstName(const std::string& firstName){
  if(firstName.length() == 0){
    throw std::invalid_argument("Error in method setFirstName of class Contact :\n\nfirstName is invalid\n"+this->getDebugValues(0));
  }else{
    this->firstName = firstName;
  }
}

/**
 * @brief Sets the lastname of a contact. Must at least contain one character
 * 
 * @throw invalid_argument lastName length must be higher than 0 
 * @param lastName 
 */
void Contact::setLastName(const std::string& lastName){
  if(lastName.length() == 0){
    throw std::invalid_argument("Error in method setLastName of class Contact :\n\nlastName is invalid\n"+this->getDebugValues(0));
  }else{
    this->lastName = lastName;
  }
}

/**
 * @brief Sets the Company of a contact. Must at least have one character
 * 
 * @throw invalid_argument enterprise length must be higher than 0  
 * @param enterprise 
 */
void Contact::setEnterprise(const std::string& enterprise){
  if(enterprise.length() == 0){
    throw std::invalid_argument("Error in method setEnterprise of class Contact :\n\nenterprise is invalid\n"+this->getDebugValues(0));
  }else{
    this->enterprise = enterprise;
  }
}

/**
 * @brief Sets the email of a contact. Must at least have one character, one @ and one "."
 * 
 * @throw invalid_argument enterprise length must be higher than 0 and one @ and one "."
 * @param mail 
 */
void Contact::setMail(const std::string& mail){
  if(mail.length() == 0 && !mail.find('@') && !mail.find('.')){
    // We check if mail isn't empty, if it contains an @ and a .
    throw std::invalid_argument("Error in method setMail of class Contact :\n\nmail is invalid\n"+this->getDebugValues(0));
  }else{
    this->mail = mail;
    if(!this->inConstructor){
      // We check if we aren't in constructor so we know we edited mail of contact and add it to logs 
      logs->add(Log(this,Log::ACTION_EDIT_MAIL));
    }
  }
}

/** 
 * @brief set phone of a contact. Must at least have one character
 * 
 * @throw invalid_argument phone length must be higher than 0 
 * @param lastName
 */
void Contact::setPhone(const std::string& phone){
  if(phone.length() == 0){
    throw std::invalid_argument("Error in method setPhone of class Contact :\n\nphone is invalid\n"+this->getDebugValues(0));
  }else{
    this->phone = phone;
    if(!this->inConstructor){
      // We check if we aren't in constructor so we know we edited phone number of contact and add it to logs 
      logs->add(Log(this,Log::ACTION_EDIT_PHONE));
    }
  }
}

/**
 * @brief Set the date of creation of the contact. Represent when he was created
 * 
 * @param dateOfCreation 
 */
void Contact::setDateOfCreation(){
  this->dateOfCreation = Date();
}

/**
 * @brief 
 * 
 * @param photo 
 */
void Contact::setPhoto(const Photo& photo){
  this->photo = photo;
  if(!this->inConstructor){
    // We check if we aren't in constructor so we know we edited photo of contact and add it to logs 
    logs->add(Log(this,Log::ACTION_EDIT_PHOTO_CONTACT));
  }
}


/**
 * @brief Adds an interaction to the list from a pointer. If the action is performed correctly, adds the creation to the logs.
 * 
 * @param Interaction *
 */
void Contact::addInteraction(Interaction * interaction){
  this->getInteractions().push_back(interaction);
  logs->add(Log(this,Log::ACTION_CREATION_INTERACTION));
}


/**
 * @brief Return firstname of client
 * 
 * @return std::string 
 */
std::string Contact::getFirstName(){
  return this->firstName;
}

/**
 * @brief Return lastname of client 
 * 
 * @return std::string 
 */
std::string Contact::getLastName(){
  return this->lastName;
}

/**
 * @brief Return enterprise of client
 * 
 * @return std::string 
 */
std::string Contact::getEnterprise(){
  return this->enterprise;
}

/**
 * @brief Return mail of client
 * 
 * @return std::string 
 */
std::string Contact::getMail(){
  return this->mail;
}

/**
 * @brief Return the phone number of client
 * 
 * @return std::string 
 */
std::string Contact::getPhone(){
  return this->phone;
}

/**
 * @brief Return Photo which contain path to real image
 * 
 * @return Photo 
 */
Photo Contact::getPhoto(){
  return this->photo;
}

/**
 * @brief Return Date which represent when the contact was created
 * 
 * @return Date 
 */
Date Contact::getDateOfCreation(){
  return this->dateOfCreation;
}

/**
 * @brief 
 * 
 * @return std::list<Interaction *> 
 */
std::list<Interaction *> Contact::getInteractions(){
  return this->interactions;
}

/**
 * @brief Removes an interaction from its index in the list using iterators. If the action is performed correctly, adds the deletion to the logs.
 * 
 * @param i 
 */
void Contact::removeInteraction(int i){
  if(i < this->getInteractions().size()){
    std::list<Interaction *>::iterator index = this->getInteractions().begin();
    std::advance(index,i);
    index = this->getInteractions().erase(index);
    logs->add(Log(this,Log::ACTION_DELETE_INTERACTION));
  }
}

/**
 * @brief returns Contact values ( firstname, lastname, mail ... ), which is suitable for debugging
 * 
 * @param nbTabulations Number of tabulations you want before showing informations. 
 * If you call outside of getDebugValues function you should set this value to 0. 
 * Also if you're inside DebugValues you should set this value to nbTabulations+1 for others getDebugsValues()
 * @return std::string 
 */
std::string Contact::getDebugValues(int nbTabulations){
  std::string tabulations = "";
  for(int x = 0;x<nbTabulations;x++){
    tabulations+="  ";
  }
	return "\n"+tabulations+"Contact{"+
  "\n  "+tabulations+"First name = "+this->firstName+
  "\n  "+tabulations+"Last name = "+this->lastName+
  "\n  "+tabulations+"Enterprise = "+this->enterprise+
  "\n  "+tabulations+"Mail = "+this->mail+
  "\n  "+tabulations+"Phone = "+this->phone+
  "\n  "+tabulations+"Date of creation = "+this->dateOfCreation.getDebugValues(nbTabulations+1)+
  "\n  "+tabulations+"Photo = "+this->photo.getDebugValues(nbTabulations+1)+
  "\n"+tabulations+"}\n";
}

/**
 * @brief Compares Contact objects and determines if they're equals
 * 
 * @param toCompare 
 * @return bool
 */
bool Contact::operator==(const Contact &toCompare){
  return true
  && this->firstName == toCompare.firstName 
  && this->lastName == toCompare.lastName
  && this->enterprise == toCompare.enterprise
  && this->mail == toCompare.mail
  && this->phone == toCompare.phone
  && this->photo == toCompare.photo
  && this->dateOfCreation == toCompare.dateOfCreation;
}