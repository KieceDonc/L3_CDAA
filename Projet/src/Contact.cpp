#include "../headers/Contact.h"

/**
 * @class 
 * 
 */

/**
 * @brief Construct a new Contact:: Contact object
 * 
 * @param logs will contains all actions / logs on this contact
 * @param firstName 
 * @param lastName 
 * @param enterprise 
 * @param mail 
 * @param phone 
 * @param photo 
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
 * @brief set firstname of a contact. Must at least have one character
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
 * @brief set lastname of a contact. Must at least have one character
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
 * @brief set enterprise of a contact. Must at least have one character
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
 * @brief set email of a contact. Must at least have one character, one @ and one "."
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
 * @brief 
 * 
 * @param Interaction *
 */
void Contact::addInteraction(Interaction * interaction){
  this->getInteractions().push_back(interaction);
}


/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Contact::getFirstName(){
  return this->firstName;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Contact::getLastName(){
  return this->lastName;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Contact::getEnterprise(){
  return this->enterprise;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Contact::getMail(){
  return this->mail;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Contact::getPhone(){
  return this->phone;
}

/**
 * @brief
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
 * @brief Compares Contact and determines if they're equal
 * 
 * @param toCompare 
 * @return true 
 * @return false 
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