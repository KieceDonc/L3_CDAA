#include "../headers/Contact.h"

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
  this->setDateOfCreation(Date());
  this->setPhoto(photo);
  this->interactions = std::list<Interaction *>();

  logs->add(Log(this,Log::ACTION_CREATION_CONTACT));
  this->inConstructor = false;
}

/**
 * @brief 
 * 
 * @param firstName 
 */
void Contact::setFirstName(const std::string& firstName){
  if(firstName.length() == 0){
    throw std::invalid_argument("Error in method setFirstName of class Contact :\n\nfirstName is invalid\n"+getDebugValues());
  }else{
    this->firstName = firstName;
  }
}

/**
 * @brief 
 * 
 * @param lastName 
 */
void Contact::setLastName(const std::string& lastName){
  if(lastName.length() == 0){
    throw std::invalid_argument("Error in method setLastName of class Contact :\n\nlastName is invalid\n"+getDebugValues());
  }else{
    this->lastName = lastName;
  }
}

/**
 * @brief 
 * 
 * @param enterprise 
 */
void Contact::setEnterprise(const std::string& enterprise){
  if(enterprise.length() == 0){
    throw std::invalid_argument("Error in method setEnterprise of class Contact :\n\nenterprise is invalid\n"+getDebugValues());
  }else{
    this->enterprise = enterprise;
  }
}

/**
 * @brief 
 * 
 * @param mail 
 */
void Contact::setMail(const std::string& mail){
  if(mail.length() == 0 && !mail.find('@') && !mail.find('.')){
    // We check if mail isn't empty, if it contains an @ and a .
    throw std::invalid_argument("Error in method setMail of class Contact :\n\nmail is invalid\n"+getDebugValues());
  }else{
    this->mail = mail;
    if(!this->inConstructor){
      logs->add(Log(this,Log::ACTION_EDIT_MAIL));
    }
  }
}

/**
 * @brief 
 * 
 * @param phone 
 */
void Contact::setPhone(const std::string& phone){
  if(phone.length() == 0){
    throw std::invalid_argument("Error in method setPhone of class Contact :\n\nphone is invalid\n"+getDebugValues());
  }else{
    this->phone = phone;
    if(!this->inConstructor){
      logs->add(Log(this,Log::ACTION_EDIT_PHONE));
    }
  }
}

/**
 * @brief 
 * 
 * @param dateOfCreation 
 */
void Contact::setDateOfCreation(const Date& dateOfCreation){
  this->dateOfCreation = dateOfCreation;
}

/**
 * @brief 
 * 
 * @param photo 
 */
void Contact::setPhoto(const Photo& photo){
  this->photo = photo;
  if(!this->inConstructor){
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
 * @brief 
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
 * @brief returns Contact object values ( firstname, lastname, mail ... ), which is suitable for debugging
 * 
 * @return std::string 
 */
std::string Contact::getDebugValues(){
	return "\nDebug values :\nContact{\n	First name = "+
	this->firstName+"\n	Last name = "+
	this->lastName+"\n	Enterprise = "+
	this->enterprise+"\n Mail = "+
  this->mail+"\n	Phone = "+
  this->phone+"\n	Date of creation = "+
  this->dateOfCreation.getDebugValues()+"\n	Photo = "+
  this->photo.getDebugValues()+"\n}\n";
}

/**
 * @brief Compares Contact objects and determines if they're equal
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